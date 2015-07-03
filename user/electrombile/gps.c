/*
 * gps.c
 *
 *  Created on: 2015/6/25
 *      Author: jk
 */

#include <eat_interface.h>
#include <eat_gps.h>

#include "gps.h"
#include "timer.h"
#include "thread.h"
#include "msg.h"
#include<string.h>
#include <stdlib.h>

#define NMEA_BUFF_SIZE 1024
static char gps_info_buf[NMEA_BUFF_SIZE]="";

static void gps_timer_handler();

void app_gps_thread(void *data)
{
    EatEvent_st event;

    eat_gps_power_req(EAT_TRUE);

    eat_trace("gps current sleep mode %d", eat_gps_sleep_read());

    eat_timer_start(TIMER_GPS, 30000);

    while(EAT_TRUE)
    {
        eat_get_event_for_user(THREAD_GPS, &event);
        switch(event.event)
        {
            case EAT_EVENT_TIMER :

                switch ( event.data.timer.timer_id )
                {
                    case TIMER_GPS:
                        eat_trace("INFO: TIMER_GPS expire!");
                        gps_timer_handler();
                        eat_timer_start(event.data.timer.timer_id, 30000);
                        break;


                    default:
                        eat_trace("ERR: timer[%d] expire!");

                        break;
                }
                break;

            case EAT_EVENT_MDM_READY_RD:
//                eat_modem_ready_read_handler();
                break;

            case EAT_EVENT_MDM_READY_WR:

                break;
            case EAT_EVENT_USER_MSG:

                break;
            default:
                break;

        }
    }
}

static void gps_timer_handler()
{
	char * GPSIM_data[9];
	char *buffer;
	double lat,lon;
	char gps_fix;
	int i;
	eat_gps_nmea_info_output(EAT_NMEA_OUTPUT_GPGGA, gps_info_buf,NMEA_BUFF_SIZE);
	eat_trace("EAT_NMEA_OUTPUT_SIMCOM=%s", gps_info_buf);

	buffer = gps_info_buf;
	for(i=0;i<7;i++)
	{
		GPSIM_data[i] = strtok(buffer,",");
		buffer = NULL;		
	}
	lat = atof(GPSIM_data[2]);
	lon =  atof(GPSIM_data[4]);
	gps_fix = atoi(GPSIM_data[6]);
	if(!gps_fix)
		return;
	
	gps_sendGPS(lat,lon);
	eat_trace("%s,%s,%s,%s,%s,%s,%s",GPSIM_data[0],GPSIM_data[1],GPSIM_data[2],GPSIM_data[3],GPSIM_data[4],GPSIM_data[5],GPSIM_data[6]);
	eat_trace("lat=%f,lon=%f,fix=%d",lat,lon,gps_fix);
}

static eat_bool gps_sendMsg2Main(MSG* msg, u8 len)
{
    return sendMsg(THREAD_VIBRATION, THREAD_MAIN, msg, len);
}

static eat_bool gps_sendGPS(double lat,double lon)
{
    u8 msgLen = sizeof(MSG) + sizeof(MSG_GPS);
    MSG* msg = allocMsg(msgLen);
    
    //TODO:
    MSG_GPS* gps = (MSG_GPS*)msg->data;
    gps->latitude = lat;
    gps->longitude = lon;

    return gps_sendMsg2Main(msg, msgLen);
}

