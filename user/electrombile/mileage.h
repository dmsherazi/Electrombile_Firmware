#ifndef MILEAGE_H
#define MILEAGE_H

#include <eat_type.h>

#define MAX_MILEAGE_LARGE 60

typedef enum
{
    SETTINGFILE,
    MILEAGEFILE

}FILE_NAME;


typedef struct
{
    float voltage[MAX_MILEAGE_LARGE];
    float dump_mileage[MAX_MILEAGE_LARGE];

}DumpVoltage;



void mileage_initial(void);


eat_bool mileage_restore(void);



#define MILEAGEFILE_NAME   L"C:\\mileage.txt"

/*                             60V电源 100k&3k分压 没有初始里程数据
#define mileage_initial_60 {{1.747600,1.735175,1.722750,1.710325,1.697900,\
                          1.685475,1.673050,1.660625,1.648200,1.635775,\
                          1.623350,1.610925,1.598500,1.586075,1.573650,\
                          1.561225,1.548800,1.536375,1.523950,1.511525,\
                          1.499100,1.486675,1.474250,1.461825,1.449400,\
                          1.436975,1.424550,1.412125,1.399700,1.387275,\
                          1.374850,1.362425,1.350000,1.337575,1.325150,\
                          1.312725,1.300300,1.287875,1.275450,1.263025\
                          },\
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\
                         }}
                                                                                */

/*                             48V电源 100k&3k分压 没有初始里程数据
#define mileage_initial_48 {{1.398058,1.393204,1.388350,1.383495,1.378641,\
                          1.373786,1.368932,1.364078,1.359223,1.354369,\
                          1.349515,1.344660,1.339806,1.334951,1.330097,\
                          1.325243,1.320388,1.315534,1.310680,1.305825,\
                          1.300971,1.296117,1.291262,1.286408,1.281553,\
                          1.276699,1.271845,1.266990,1.262136,1.257282,\
                          1.252427,1.247573,1.242718,1.237864,1.233010,\
                          1.228155,1.223301,1.218447,1.213592,1.208938\
                          },\
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\
                         }}
                                                                                */


#endif//MILEAGE_H

