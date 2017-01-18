#include <eat_interface.h>

#include "fs.h"
#include "audio_source.h"

static const u8 audio_BluetoothFound_Source[]=
{/*hello.amr*/
  0x23, 0x21, 0x41, 0x4D, 0x52, 0x0A, 0x2C, 0xB4, 0x00, 0x9A, 0x00, 0x1E, 0x79, 0xFF, 0xE1, 0x84,
  0x67, 0x80, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xE3, 0xA5, 0x6F, 0x2A,
  0x5B, 0x6C, 0x18, 0x71, 0x5F, 0xB0, 0x34, 0x05, 0x9F, 0x2C, 0x7C, 0x07, 0xED, 0xFB, 0x60, 0x5E,
  0x2C, 0xF5, 0xA8, 0xEC, 0xD2, 0x77, 0x67, 0x43, 0x4E, 0x8E, 0xB0, 0xE3, 0x65, 0x68, 0xF7, 0x33,
  0x06, 0x6D, 0x5F, 0x3D, 0x92, 0x2C, 0xC9, 0x19, 0x7D, 0x2D, 0xC0, 0x09, 0x1C, 0x2D, 0x0B, 0x6B,
  0x71, 0xA7, 0xFB, 0xE4, 0x5C, 0xA9, 0x94, 0x45, 0x5A, 0x54, 0x2C, 0x03, 0x6A, 0xE1, 0xCA, 0x0C,
  0xC0, 0x30, 0xCA, 0xF6, 0x0A, 0xC5, 0xEF, 0x29, 0x89, 0x8A, 0xCA, 0x6E, 0x50, 0x89, 0x56, 0x2C,
  0x4A, 0x56, 0xC4, 0xD3, 0x2F, 0xA0, 0x79, 0xFB, 0xF5, 0xBB, 0x40, 0x96, 0x69, 0x01, 0xA3, 0x64,
  0x90, 0x32, 0x13, 0x08, 0x2C, 0x2F, 0x7C, 0x86, 0x1F, 0xFF, 0x81, 0x86, 0x1E, 0x02, 0x22, 0xF3,
  0x9E, 0x5F, 0x8E, 0x29, 0x24, 0x21, 0x42, 0x7A, 0x0E, 0x2C, 0x2E, 0xE3, 0xCD, 0x2C, 0x9F, 0x21,
  0x83, 0x4E, 0x53, 0xF6, 0xB7, 0x40, 0x3D, 0xF9, 0xBB, 0x82, 0x04, 0xF1, 0x66, 0x22, 0x2C, 0x38,
  0x15, 0x1C, 0x5B, 0xFE, 0xE1, 0x86, 0x0B, 0x91, 0xAB, 0x05, 0x9A, 0x83, 0xCB, 0x83, 0xAE, 0x96,
  0x0C, 0xF8, 0xDC, 0x2C, 0x30, 0x21, 0x8F, 0x68, 0xFF, 0x01, 0x9E, 0x18, 0x1A, 0xCC, 0xF3, 0x6C,
  0x9C, 0x05, 0x8B, 0x28, 0x1D, 0x4C, 0x96, 0x9C, 0x2C, 0x26, 0x86, 0x99, 0xE0, 0x5C, 0x41, 0xB6,
  0x01, 0x0A, 0x2E, 0x2F, 0x2B, 0x6C, 0xF2, 0xF7, 0x14, 0xEF, 0x04, 0x59, 0x3E, 0x2C, 0x80, 0xEF,
  0x1F, 0xE0, 0x10, 0xCB, 0xC3, 0x1F, 0x5B, 0x42, 0x78, 0x97, 0x12, 0x68, 0xFD, 0x14, 0x39, 0x1C,
  0x1D, 0x50, 0x2C, 0x27, 0xF0, 0xCD, 0xE1, 0x81, 0x8B, 0x3E, 0x86, 0x92, 0x02, 0x61, 0xD7, 0xC5,
  0x3F, 0x54, 0xCD, 0xC9, 0x89, 0xD1, 0xA8, 0x2C, 0x3B, 0xB6, 0x45, 0xE0, 0xDF, 0xC1, 0x91, 0x97,
  0x75, 0xFA, 0x2C, 0x7A, 0x68, 0x94, 0xF2, 0x92, 0x89, 0x72, 0xAD, 0x80, 0x2C, 0x64, 0x64, 0x32,
  0xF9, 0xBE, 0x60, 0x79, 0xF0, 0xF7, 0x68, 0x92, 0xA6, 0xA4, 0xC3, 0x54, 0x81, 0x01, 0x3D, 0xC3,
  0x22, 0x2C, 0x6A, 0x53, 0xB5, 0xE1, 0x5E, 0x81, 0x2C, 0xAE, 0xBE, 0xAB, 0x69, 0x3A, 0x85, 0x47,
  0x92, 0x84, 0x95, 0x40, 0xC4, 0xE2, 0x2C, 0x65, 0x8C, 0xC5, 0xE9, 0x1E, 0x00, 0x79, 0xE3, 0x51,
  0xA7, 0xC0, 0x5E, 0xA2, 0x60, 0x6D, 0x40, 0x57, 0x14, 0x4E, 0xE6, 0x2C, 0x61, 0x3B, 0x8F, 0xE0,
  0x9E, 0x00, 0x71, 0x82, 0xF8, 0x34, 0x2F, 0xD7, 0xFC, 0xD0, 0xA8, 0x22, 0x56, 0x0F, 0x5C, 0xC8,
  0x2C, 0x54, 0x49, 0xC5, 0xE0, 0x1E, 0x00, 0x61, 0x80, 0x09, 0x71, 0x92, 0x05, 0xDE, 0x57, 0x46,
  0xF3, 0x59, 0x65, 0xBC, 0x98, 0x2C, 0x2F, 0x07, 0x67, 0x68, 0x85, 0xA0, 0x18, 0x79, 0xFB, 0xD9,
  0x9A, 0x74, 0x72, 0x79, 0x26, 0xAC, 0x8C, 0xC5, 0x33, 0x7C, 0x2C, 0x1F, 0xFC, 0x9C, 0x97, 0x72,
  0xC0, 0x18, 0x63, 0xF6, 0xC2, 0xD1, 0x0C, 0x17, 0xCD, 0xB8, 0xB2, 0x10, 0x41, 0xA0, 0x8C, 0x2C,
  0x1F, 0xFC, 0x9D, 0x0E, 0xBE, 0x20, 0x18, 0x6B, 0xD6, 0x4B, 0x06, 0x51, 0x03, 0x59, 0xC2, 0xA3,
  0x63, 0xA1, 0x08, 0xC8, 0x2C, 0x1F, 0x35, 0xEB, 0x0E, 0x5E, 0x00, 0x18, 0x64, 0x13, 0x45, 0x20,
  0x89, 0x7C, 0xD3, 0xDC, 0x50, 0x71, 0xBF, 0x86, 0x7A, 0x2C, 0x36, 0xEE, 0x9D, 0x0E, 0xDF, 0xA0,
  0x10, 0x42, 0xAE, 0xAA, 0x44, 0x40, 0x76, 0x46, 0x66, 0x60, 0x12, 0x45, 0x5E, 0x2C, 0x2C, 0x1E,
  0x08, 0xEA, 0x3D, 0x5F, 0x00, 0x08, 0x7B, 0x31, 0xF8, 0x2C, 0x86, 0xE3, 0x6B, 0x84, 0x6E, 0xE8,
  0x80, 0x1C, 0x88, 0x2C, 0x1C, 0x4B, 0x9C, 0x79, 0x8D, 0xC0, 0x61, 0x26, 0xA6, 0x14, 0x71, 0xE6,
  0x81, 0x4B, 0x2A, 0x38, 0xC9, 0x23, 0x7A, 0xF6, 0x2C, 0x1C, 0xEE, 0xE0, 0x1F, 0x6F, 0xE0, 0x61,
  0x98, 0x1E, 0x62, 0xC7, 0xAC, 0x18, 0x72, 0x82, 0x64, 0x08, 0x04, 0x4F, 0x82, 0x2C, 0x25, 0xF7,
  0x9C, 0x1F, 0xFE, 0x00, 0x61, 0x90, 0xBF, 0x1C, 0xBA, 0xC4, 0x4C, 0x86, 0x2C, 0xC2, 0x1A, 0x13,
  0x43, 0xF0, 0x2C, 0x4A, 0x22, 0x4C, 0xF1, 0x1E, 0x20, 0x7B, 0x58, 0x82, 0x13, 0xCD, 0xAC, 0x21,
  0x94, 0x39, 0x88, 0x44, 0x81, 0xEA, 0x02, 0x2C, 0x1A, 0xA2, 0xA7, 0x68, 0xDA, 0x41, 0x9C, 0xB8,
  0xAC, 0xB9, 0xC2, 0x2E, 0x34, 0x99, 0x55, 0x84, 0x2A, 0x03, 0x72, 0xD8, 0x2C, 0x26, 0x4B, 0xB6,
  0xB4, 0xDE, 0x41, 0xE6, 0x11, 0x8A, 0xA7, 0x93, 0xA6, 0x36, 0x31, 0x47, 0x4A, 0x88, 0x51, 0xF0,
  0x46, 0x2C, 0x24, 0xEE, 0x36, 0x1F, 0x5E, 0x01, 0xF4, 0xAE, 0xB2, 0xA2, 0x0D, 0x3D, 0xF8, 0x0C,
  0x47, 0xA2, 0xF0, 0x94, 0xCE, 0x90, 0x2C, 0x26, 0xEE, 0xEA, 0x1F, 0xFC, 0x61, 0xC9, 0xF6, 0xF1,
  0x70, 0x1F, 0xDE, 0x96, 0x1D, 0x2A, 0x7C, 0x1F, 0x6A, 0xE9, 0xDA, 0x2C, 0x26, 0x57, 0xC0, 0x1E,
  0xFE, 0x21, 0x81, 0xFB, 0x53, 0x8F, 0x50, 0x96, 0x14, 0x12, 0x34, 0xBA, 0x07, 0x7B, 0x83, 0x2A,
  0x2C, 0x0F, 0x8E, 0x8E, 0x96, 0x34, 0xA0, 0x79, 0xF1, 0x8A, 0x59, 0xD1, 0xBE, 0x22, 0xCB, 0x08,
  0xE9, 0xF0, 0xE8, 0xE6, 0xCA, 0x2C, 0x4A, 0xD5, 0xEB, 0x0E, 0xE1, 0x02, 0xDF, 0xC5, 0xD0, 0x24,
  0xBA, 0x59, 0x39, 0x20, 0x65, 0xA6, 0x78, 0x2F, 0x6D, 0xF0, 0x2C, 0xC5, 0xC2, 0x0D, 0x2C, 0xC0,
  0x20, 0x6F, 0x28, 0x1F, 0x9C, 0x57, 0xB1, 0x68, 0x42, 0xAD, 0x32, 0x4E, 0xAE, 0x9C, 0x4C, 0x2C,
  0xE0, 0x1C, 0x8E, 0x79, 0x83, 0x35, 0xF1, 0xFB, 0x49, 0x44, 0x90, 0x4E, 0x6E, 0x65, 0x4F, 0x6F,
  0x9F, 0xAA, 0x82, 0x64, 0x2C, 0xD9, 0xC2, 0x8E, 0x5A, 0xA1, 0x7C, 0xCA, 0x78, 0x79, 0x58, 0x86,
  0x25, 0x3B, 0xB8, 0x4F, 0x59, 0x33, 0xFB, 0xF2, 0x92, 0x2C, 0xD0, 0xD5, 0x8F, 0xE0, 0x00, 0x42,
  0xE2, 0x41, 0xD0, 0xB7, 0xE4, 0x2E, 0xB4, 0xC8, 0x8A, 0xE9, 0xAD, 0x83, 0xA2, 0xB6, 0x2C, 0x69,
  0xAC, 0x37, 0xCB, 0x28, 0xE0, 0xCB, 0x63, 0x94, 0x54, 0x96, 0xA9, 0x6B, 0x68, 0xEA, 0x7B, 0x8A,
  0x2B, 0x19, 0x08, 0x2C, 0xD0, 0x01, 0xE1, 0xE0, 0x1F, 0xE3, 0x56, 0x08, 0x66, 0x71, 0xD6, 0xA5,
  0x90, 0xCE, 0x97, 0x87, 0xB4, 0x0A, 0x19, 0xB8, 0x2C, 0xA3, 0x4F, 0xC1, 0xE0, 0x1C, 0x26, 0x1E,
  0x08, 0x89, 0xB7, 0xFB, 0x78, 0x8C, 0x63, 0xDB, 0x4E, 0xF6, 0x58, 0x47, 0x66, 0x2C, 0xC4, 0x54,
  0x8F, 0xE0, 0x1E, 0x86, 0x7E, 0x0C, 0x80, 0xBB, 0x18, 0x52, 0x75, 0x46, 0xD6, 0x04, 0x06, 0x92,
  0x32, 0x14, 0x2C, 0xA2, 0xF6, 0xC0, 0x79, 0x81, 0xE7, 0x8E, 0x18, 0x28, 0xC4, 0xFF, 0xD0, 0x18,
  0x4D, 0x33, 0x3C, 0x8E, 0x4C, 0x60, 0xFA, 0x2C, 0xA6, 0xF6, 0xC0, 0x97, 0x6B, 0x47, 0xEE, 0x0C,
  0x02, 0x19, 0x43, 0xF8, 0x28, 0x3A, 0xF9, 0x78, 0x94, 0x70, 0x08, 0x86, 0x2C, 0xA1, 0x2D, 0x42,
  0x5B, 0x6B, 0x47, 0xFE, 0x29, 0x86, 0xF9, 0x1B, 0x82, 0x0D, 0x5A, 0x52, 0x35, 0x15, 0x01, 0x7A,
  0xBE, 0x2C, 0xA0, 0x6A, 0xC0, 0x1F, 0xC9, 0x38, 0x9C, 0xEB, 0x33, 0xA8, 0x74, 0x1F, 0x9B, 0x75,
  0xBA, 0xDE, 0x66, 0xC8, 0x53, 0x16, 0x2C, 0x68, 0x6A, 0x8E, 0x1F, 0xA0, 0x9C, 0xAE, 0x51, 0x91,
  0x38, 0x4D, 0xFC, 0x91, 0xD4, 0x3F, 0x27, 0x28, 0x32, 0x22, 0xBC, 0x2C, 0x52, 0xE4, 0x8E, 0x17,
  0x81, 0x9E, 0xDB, 0x54, 0x31, 0x7A, 0x2E, 0x55, 0xE7, 0xC5, 0x12, 0x34, 0x7D, 0x2A, 0x66, 0x0A,
  0x2C, 0x44, 0xE3, 0x8E, 0x19, 0x11, 0x06, 0xBE, 0x0F, 0xDA, 0x13, 0x05, 0xD0, 0xDE, 0x6A, 0xBA,
  0xEC, 0x34, 0xFC, 0xB3, 0x84, 0x2C, 0xC0, 0x1E, 0x8E, 0x00, 0x00, 0x1F, 0xDF, 0xAD, 0x83, 0x76,
  0x18, 0x7E, 0xFE, 0x05, 0xFF, 0xF9, 0x17, 0x03, 0x4C, 0x34, 0x2C, 0xD1, 0x1A, 0x7C, 0x08, 0x0C,
  0x19, 0xFF, 0xE9, 0x82, 0x66, 0x41, 0xBC, 0xE0, 0x53, 0xE1, 0xF4, 0x5A, 0x81, 0xF0, 0x20, 0x2C,
  0xC5, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8,
  0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00,
  0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0xA9, 0xCC, 0x00, 0x1F, 0xF9,
  0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1,
  0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20,
  0x82, 0x00, 0x00, 0x2C, 0xC5, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F,
  0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF,
  0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0xA9,
  0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82,
  0x00, 0x00, 0x2C, 0xD1, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0,
  0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1,
  0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0x1A, 0xCC,
  0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00,
  0x00, 0x2C, 0xC5, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03,
  0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00
};

static const u8 audio_BluetoothLost_Source[]=
{/*goodbye.amr*/
  0x23, 0x21, 0x41, 0x4D, 0x52, 0x0A, 0x2C, 0xB4, 0x00, 0x9A, 0x00, 0x1E, 0x79, 0xFF, 0xE1, 0x84,
  0x67, 0x80, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xE3, 0xA5, 0x6F, 0x2A,
  0x5B, 0x6C, 0x18, 0x71, 0x5F, 0xB0, 0x34, 0x05, 0x9F, 0x2C, 0x7C, 0x07, 0xED, 0xFB, 0x60, 0x5E,
  0x2C, 0xF5, 0xA8, 0xEC, 0xD2, 0x77, 0x67, 0x43, 0x4E, 0x8E, 0xB0, 0xE3, 0x65, 0x68, 0xF7, 0x33,
  0x06, 0x6D, 0x5F, 0x3D, 0x92, 0x2C, 0xC9, 0x19, 0x7D, 0x2D, 0xC0, 0x09, 0x1C, 0x2D, 0x0B, 0x6B,
  0x71, 0xA7, 0xFB, 0xE4, 0x5C, 0xA9, 0x94, 0x45, 0x5A, 0x54, 0x2C, 0x03, 0x6A, 0xE1, 0xCA, 0x0C,
  0xC0, 0x30, 0xCA, 0xF6, 0x0A, 0xC5, 0xEF, 0x29, 0x89, 0x8A, 0xCA, 0x6E, 0x50, 0x89, 0x56, 0x2C,
  0x4A, 0x56, 0xC4, 0xD3, 0x2F, 0xA0, 0x79, 0xFB, 0xF5, 0xBB, 0x40, 0x96, 0x69, 0x01, 0xA3, 0x64,
  0x90, 0x32, 0x13, 0x08, 0x2C, 0x2F, 0x7C, 0x86, 0x1F, 0xFF, 0x81, 0x86, 0x1E, 0x02, 0x22, 0xF3,
  0x9E, 0x5F, 0x8E, 0x29, 0x24, 0x21, 0x42, 0x7A, 0x0E, 0x2C, 0x2E, 0xE3, 0xCD, 0x2C, 0x9F, 0x21,
  0x83, 0x4E, 0x53, 0xF6, 0xB7, 0x40, 0x3D, 0xF9, 0xBB, 0x82, 0x04, 0xF1, 0x66, 0x22, 0x2C, 0x38,
  0x15, 0x1C, 0x5B, 0xFE, 0xE1, 0x86, 0x0B, 0x91, 0xAB, 0x05, 0x9A, 0x83, 0xCB, 0x83, 0xAE, 0x96,
  0x0C, 0xF8, 0xDC, 0x2C, 0x30, 0x21, 0x8F, 0x68, 0xFF, 0x01, 0x9E, 0x18, 0x1A, 0xCC, 0xF3, 0x6C,
  0x9C, 0x05, 0x8B, 0x28, 0x1D, 0x4C, 0x96, 0x9C, 0x2C, 0x26, 0x86, 0x99, 0xE0, 0x5C, 0x41, 0xB6,
  0x01, 0x0A, 0x2E, 0x2F, 0x2B, 0x6C, 0xF2, 0xF7, 0x14, 0xEF, 0x04, 0x59, 0x3E, 0x2C, 0x80, 0xEF,
  0x1F, 0xE0, 0x10, 0xCB, 0xC3, 0x1F, 0x5B, 0x42, 0x78, 0x97, 0x12, 0x68, 0xFD, 0x14, 0x39, 0x1C,
  0x1D, 0x50, 0x2C, 0x27, 0xF0, 0xCD, 0xE1, 0x81, 0x8B, 0x3E, 0x86, 0x92, 0x02, 0x61, 0xD7, 0xC5,
  0x3F, 0x54, 0xCD, 0xC9, 0x89, 0xD1, 0xA8, 0x2C, 0x38, 0x67, 0xD3, 0xE0, 0xBA, 0xC1, 0x91, 0xB3,
  0xF1, 0x53, 0x61, 0x16, 0x28, 0x59, 0xB2, 0x92, 0x89, 0x7A, 0x89, 0xC6, 0x2C, 0x3B, 0x4B, 0xD2,
  0xD3, 0x7E, 0x81, 0xFE, 0x11, 0x9C, 0x07, 0x4C, 0xAA, 0x03, 0x1F, 0xD1, 0x51, 0xAC, 0xAC, 0xF9,
  0x8E, 0x2C, 0x34, 0x67, 0x0F, 0xE0, 0x1E, 0x01, 0xF9, 0xE8, 0x7D, 0x56, 0x01, 0xA0, 0xBD, 0xAB,
  0xCA, 0x40, 0x8F, 0xDA, 0x80, 0x00, 0x2C, 0x22, 0xB7, 0x42, 0x5B, 0xA1, 0xE1, 0xC9, 0xE3, 0xD8,
  0xE9, 0x89, 0x28, 0x05, 0xDC, 0x27, 0x23, 0xC4, 0x49, 0x2B, 0xC2, 0x2C, 0x25, 0x92, 0xCD, 0x24,
  0xDE, 0x21, 0x91, 0xE8, 0xE0, 0xC7, 0xA8, 0x58, 0x5D, 0x43, 0xA2, 0xF2, 0x0C, 0xCB, 0x42, 0x8C,
  0x2C, 0x25, 0x8E, 0x8E, 0x1F, 0x1E, 0x01, 0x86, 0x0E, 0x07, 0x40, 0x1F, 0x07, 0x48, 0x8F, 0x33,
  0x2B, 0xD1, 0xBE, 0x9E, 0x38, 0x2C, 0x26, 0x0F, 0x8E, 0x1F, 0xB2, 0x21, 0x8C, 0x0C, 0x13, 0xC4,
  0x6A, 0xA9, 0x73, 0xB6, 0xB2, 0xC5, 0x1E, 0x42, 0x02, 0x2A, 0x2C, 0x99, 0xF0, 0x8E, 0x3C, 0xD0,
  0x00, 0x46, 0x58, 0xC2, 0x39, 0xF6, 0x30, 0xBB, 0xFF, 0x33, 0x9D, 0x97, 0x32, 0xEB, 0xCA, 0x2C,
  0xA6, 0x2C, 0x40, 0xF1, 0x08, 0x47, 0x8E, 0x48, 0x9F, 0xE7, 0xA1, 0xA2, 0xEC, 0xD4, 0xFC, 0x88,
  0x63, 0x30, 0xA2, 0x86, 0x2C, 0x3B, 0x8E, 0x66, 0xF9, 0x44, 0x60, 0x10, 0x35, 0xCA, 0x27, 0x48,
  0x8A, 0x7C, 0x84, 0xCF, 0x2E, 0x3E, 0xCA, 0x08, 0x88, 0x2C, 0x92, 0xFF, 0xBF, 0xE0, 0x3E, 0xC0,
  0x30, 0xCC, 0x57, 0x2E, 0x9A, 0xFA, 0x7F, 0x65, 0x3B, 0x8E, 0x50, 0x66, 0x6C, 0x0E, 0x2C, 0x72,
  0xA2, 0xF3, 0xE0, 0x0F, 0x00, 0x69, 0xF7, 0x2F, 0xAC, 0x3B, 0x66, 0x02, 0x34, 0xDF, 0x10, 0xA6,
  0x27, 0x76, 0x8C, 0x2C, 0x63, 0x7A, 0x1D, 0xE0, 0x5C, 0x21, 0x86, 0x0A, 0xFE, 0xE0, 0xA2, 0x73,
  0xAB, 0xAA, 0x72, 0x73, 0x64, 0xB9, 0xA5, 0x66, 0x2C, 0x39, 0xFC, 0x74, 0xB5, 0x58, 0x61, 0xB6,
  0x1B, 0x0D, 0xBA, 0x47, 0x45, 0x68, 0xD1, 0xD8, 0xD9, 0x2B, 0xA8, 0x4A, 0x1E, 0x2C, 0x15, 0xFC,
  0x7A, 0x1D, 0xF0, 0x81, 0xEE, 0x13, 0x9F, 0xB0, 0xB0, 0xF4, 0x16, 0x13, 0x8C, 0x53, 0xA0, 0x61,
  0xB8, 0xD6, 0x2C, 0x45, 0x68, 0x82, 0x1F, 0xA6, 0x04, 0xAA, 0x4D, 0x67, 0x32, 0x41, 0xC5, 0x8E,
  0x2D, 0x5D, 0x95, 0xA5, 0xD2, 0x73, 0x80, 0x2C, 0x84, 0x0A, 0x1E, 0x1E, 0x48, 0xE6, 0x13, 0x47,
  0x92, 0xBD, 0x38, 0xE6, 0xC9, 0xFE, 0x6B, 0x92, 0x3A, 0x02, 0xF6, 0xDE, 0x2C, 0xCB, 0xDE, 0x4D,
  0x68, 0x88, 0x24, 0x71, 0x69, 0x53, 0x6A, 0x73, 0xA3, 0x7C, 0x5F, 0x27, 0x52, 0xDC, 0x64, 0x53,
  0xC4, 0x2C, 0x06, 0x50, 0x2E, 0xB5, 0x41, 0x1B, 0x69, 0xB1, 0xCD, 0x1C, 0xE5, 0x99, 0xD2, 0xA0,
  0xDF, 0x54, 0xAD, 0xA7, 0x90, 0x00, 0x2C, 0x2F, 0xE1, 0xED, 0xA5, 0x59, 0xE0, 0xC6, 0x19, 0x0E,
  0xF4, 0xEB, 0x90, 0x74, 0xE8, 0xF2, 0xA8, 0x28, 0xB0, 0x4F, 0x16, 0x2C, 0x30, 0x76, 0x7B, 0x86,
  0xFF, 0x41, 0x8E, 0x1D, 0x9A, 0x53, 0xBB, 0xE2, 0xA8, 0x4B, 0x94, 0x5E, 0x01, 0x8F, 0x12, 0x14,
  0x2C, 0x3A, 0x77, 0xCD, 0xE0, 0x3E, 0xA1, 0xE6, 0x14, 0xBA, 0xC5, 0x4A, 0xF6, 0xCE, 0x68, 0xA6,
  0x6C, 0x24, 0x0D, 0x03, 0xAA, 0x2C, 0x65, 0xB6, 0x33, 0xE0, 0x3F, 0xC3, 0x56, 0x09, 0x46, 0x8A,
  0x64, 0x41, 0xC3, 0x1C, 0x76, 0x6C, 0x7A, 0x63, 0x93, 0x48, 0x2C, 0x6A, 0x64, 0x3B, 0xE1, 0x3F,
  0x06, 0x1E, 0x04, 0xA4, 0x34, 0x52, 0x87, 0xEF, 0x93, 0x4B, 0x41, 0x3D, 0x37, 0x92, 0x08, 0x2C,
  0x62, 0x20, 0x0D, 0xA4, 0x5C, 0x26, 0x6E, 0x1D, 0x3E, 0x29, 0xA7, 0x6A, 0x84, 0x73, 0x13, 0xB2,
  0x86, 0x48, 0x3F, 0x84, 0x2C, 0x3B, 0x07, 0xCD, 0x2D, 0x81, 0xA7, 0x8E, 0x05, 0x16, 0xA2, 0x5D,
  0x61, 0x86, 0x87, 0xBB, 0x87, 0x92, 0xC1, 0x2D, 0x00, 0x2C, 0x34, 0xB7, 0x0C, 0x1E, 0xC1, 0x4D,
  0x46, 0x1E, 0xA6, 0xFA, 0xA5, 0x90, 0x53, 0x60, 0xE5, 0x52, 0x34, 0x56, 0x0D, 0x00, 0x2C, 0x24,
  0x20, 0x9C, 0x1B, 0xC0, 0x16, 0x36, 0x63, 0x9E, 0x5A, 0x97, 0x63, 0x75, 0xB9, 0x6D, 0x1C, 0x48,
  0xD3, 0xC9, 0x4E, 0x2C, 0x19, 0x13, 0x60, 0x19, 0x41, 0x82, 0x66, 0xD0, 0x10, 0x5E, 0x1E, 0xF0,
  0x0A, 0x51, 0xE3, 0xAE, 0xB0, 0x21, 0x19, 0xBE, 0x2C, 0x91, 0x0D, 0x32, 0x00, 0x40, 0x1F, 0xEF,
  0xF9, 0x97, 0x46, 0x0C, 0x3D, 0xC7, 0x13, 0xE9, 0xE3, 0xC1, 0xE1, 0x23, 0xD0, 0x2C, 0xD1, 0xCD,
  0xCC, 0x00, 0x06, 0x79, 0xFF, 0xE1, 0x82, 0x66, 0x01, 0x9D, 0xF1, 0x23, 0xFF, 0xF9, 0xB6, 0x82,
  0x00, 0x00, 0x2C, 0xC5, 0x85, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0,
  0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1,
  0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC,
  0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00,
  0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03,
  0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82,
  0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00,
  0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00,
  0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF,
  0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66,
  0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F,
  0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C,
  0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8,
  0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00,
  0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00
};

static const u8 audio_Alarm[]=
{/*alarm.amr*/
  0x23, 0x21, 0x41, 0x4D, 0x52, 0x0A, 0x2C, 0x8B, 0x1C, 0x4E, 0x00, 0x1E, 0x79, 0xFF, 0xE1, 0x96,
  0x67, 0x80, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0x75, 0x1C, 0xBD, 0x08,
  0x77, 0x2A, 0xC2, 0x7F, 0x46, 0x14, 0xFA, 0x24, 0x2B, 0xCC, 0xF7, 0x0F, 0xCD, 0xE3, 0x5E, 0xF0,
  0x2C, 0x43, 0x45, 0x32, 0x1C, 0x30, 0x41, 0xCF, 0x76, 0xDF, 0x26, 0xBE, 0x52, 0x09, 0xB6, 0xD5,
  0x90, 0x19, 0xD7, 0x82, 0xBA, 0x2C, 0x87, 0x53, 0x74, 0x3C, 0x03, 0x2C, 0x1F, 0x12, 0x7D, 0x97,
  0x9C, 0x70, 0x4F, 0xC7, 0xCE, 0xFE, 0x11, 0x97, 0xF6, 0xFE, 0x2C, 0x06, 0xFD, 0xF3, 0x6C, 0x9F,
  0xD0, 0x69, 0xFA, 0x5B, 0x9D, 0xEF, 0xD4, 0x3A, 0x17, 0x43, 0x48, 0x35, 0xAB, 0xCC, 0xD4, 0x2C,
  0x2A, 0xEB, 0x1F, 0xE0, 0xCF, 0x01, 0x9E, 0x02, 0x81, 0xB4, 0xA3, 0x69, 0x11, 0x72, 0xB4, 0xF0,
  0x51, 0x40, 0x6E, 0xA6, 0x2C, 0x30, 0x74, 0xED, 0xE0, 0x7F, 0xE1, 0x9E, 0x19, 0x87, 0xE0, 0x01,
  0x54, 0x44, 0xDC, 0x6B, 0x22, 0xAE, 0x83, 0x02, 0x18, 0x2C, 0x39, 0x70, 0x4F, 0xE0, 0xFF, 0xC1,
  0x9C, 0x9F, 0xB3, 0xCB, 0xF1, 0xBA, 0x22, 0x41, 0x2A, 0xB4, 0x51, 0x96, 0xFD, 0x90, 0x2C, 0x3D,
  0x70, 0xC5, 0xE0, 0xDF, 0x21, 0x9C, 0xB7, 0x36, 0xE8, 0x7E, 0xD1, 0xFB, 0x5B, 0x2C, 0xC9, 0xE5,
  0x41, 0x06, 0xD4, 0x2C, 0x3C, 0x77, 0xB3, 0xE1, 0xBE, 0x01, 0x91, 0xE6, 0xF2, 0x99, 0x9E, 0x48,
  0xBD, 0xD0, 0x67, 0xB7, 0xAE, 0x00, 0x96, 0x18, 0x2C, 0x2E, 0x64, 0x9B, 0xE0, 0x98, 0x41, 0x2B,
  0xD4, 0xF5, 0x27, 0x84, 0x2D, 0xD0, 0x61, 0x8C, 0x9A, 0x2B, 0xDF, 0x82, 0x6E, 0x2C, 0x24, 0x99,
  0x4E, 0x1F, 0x20, 0x21, 0x39, 0xFC, 0xC6, 0x4F, 0x21, 0xAE, 0xC3, 0x21, 0x95, 0x0C, 0x75, 0x17,
  0x4D, 0x26, 0x2C, 0x53, 0x10, 0xFC, 0x1F, 0x00, 0xC0, 0x79, 0xE2, 0x16, 0xED, 0x08, 0x3D, 0x00,
  0xD1, 0x2C, 0x60, 0x55, 0xA7, 0x57, 0xF6, 0x2C, 0x74, 0x91, 0x8E, 0x9E, 0xC0, 0x02, 0x42, 0xDB,
  0x81, 0x1D, 0x08, 0x64, 0xF2, 0x5D, 0xED, 0x5F, 0x2F, 0xE4, 0xCD, 0x4A, 0x2C, 0xDC, 0x1C, 0x2D,
  0x69, 0xC0, 0xF5, 0x0D, 0x39, 0x90, 0x9B, 0x00, 0x87, 0xA0, 0x8E, 0x6D, 0x39, 0xDE, 0xB9, 0xFA,
  0x70, 0x2C, 0xBE, 0x01, 0x0D, 0xA4, 0x6A, 0x15, 0x40, 0x64, 0x1F, 0xBD, 0x0C, 0x59, 0x0B, 0xFC,
  0xEE, 0x37, 0xC2, 0xEE, 0x18, 0xA0, 0x2C, 0x49, 0xAC, 0x63, 0xE0, 0x62, 0xA4, 0x31, 0x61, 0x52,
  0xD5, 0x5E, 0xD3, 0x96, 0x71, 0xAC, 0x85, 0x86, 0x70, 0x89, 0x36, 0x2C, 0x57, 0x98, 0x79, 0xA5,
  0x76, 0x80, 0x00, 0x05, 0xE9, 0xD2, 0x72, 0x02, 0xA4, 0x92, 0x78, 0xEC, 0xC9, 0x69, 0xA9, 0xA2,
  0x2C, 0x54, 0x63, 0xC1, 0x86, 0x7C, 0x20, 0x00, 0x3F, 0xC2, 0xE4, 0x3C, 0xE5, 0x9E, 0x15, 0x4B,
  0x50, 0x78, 0xE3, 0xC7, 0x2E, 0x2C, 0x36, 0x4F, 0x9D, 0xC2, 0x3C, 0x20, 0x18, 0xCA, 0xC6, 0x40,
  0x8E, 0xAC, 0x21, 0xF8, 0x23, 0xC3, 0x9C, 0x0F, 0x00, 0x7A, 0x2C, 0x25, 0x7C, 0xE1, 0x86, 0x3F,
  0x80, 0x61, 0x86, 0x1E, 0x2C, 0x8F, 0x75, 0x5B, 0x51, 0x26, 0xE2, 0x44, 0x00, 0xFC, 0xC2, 0x2C,
  0x16, 0xEE, 0x8F, 0xE1, 0x1B, 0xC0, 0x61, 0x88, 0x9F, 0x7E, 0x04, 0x25, 0x6D, 0x52, 0xAF, 0x04,
  0x80, 0x1F, 0x48, 0x1A, 0x2C, 0x1C, 0x57, 0x8F, 0x86, 0x65, 0x60, 0x69, 0xF9, 0x06, 0x61, 0x82,
  0xBC, 0x5A, 0x05, 0x4C, 0xB2, 0x30, 0x41, 0x75, 0x86, 0x2C, 0x17, 0x32, 0x8E, 0x1F, 0xA6, 0x00,
  0x71, 0xE8, 0xD3, 0x3F, 0xAF, 0x0D, 0xDA, 0x48, 0xCD, 0x02, 0xD8, 0x65, 0x70, 0xCC, 0x2C, 0x25,
  0x7D, 0x9C, 0xC3, 0x1E, 0xC0, 0x79, 0xE2, 0x9F, 0x3B, 0x26, 0xD1, 0x76, 0x76, 0xC6, 0xE7, 0x7A,
  0x68, 0x11, 0xB8, 0x2C, 0x2E, 0xED, 0x8E, 0x97, 0x76, 0xE0, 0xD3, 0x45, 0x63, 0x65, 0x5C, 0xF6,
  0x03, 0xEE, 0x14, 0x3B, 0x0B, 0xD1, 0x9A, 0xC8, 0x2C, 0x3C, 0x4A, 0x9C, 0x79, 0x9D, 0xA1, 0x8E,
  0x3B, 0x87, 0x75, 0xDC, 0xEF, 0x99, 0xD0, 0xA3, 0xC0, 0x6C, 0x50, 0xED, 0x72, 0x2C, 0x54, 0x2D,
  0xB5, 0xA4, 0x7F, 0x63, 0x56, 0x00, 0x7E, 0x1A, 0x8C, 0x85, 0xE8, 0x75, 0x76, 0x82, 0x4A, 0x0B,
  0x72, 0x1E, 0x2C, 0x66, 0xE4, 0x0D, 0xC2, 0x3E, 0xE6, 0x1B, 0x46, 0xE6, 0x55, 0x22, 0xDA, 0x87,
  0x7B, 0x90, 0xBA, 0x00, 0x7D, 0xA9, 0x34, 0x2C, 0x6B, 0x9C, 0x8F, 0xE0, 0x1E, 0x26, 0x6C, 0xB3,
  0x28, 0xFA, 0xD4, 0xAC, 0xBA, 0xE1, 0x1C, 0x76, 0x41, 0x46, 0xBC, 0xE0, 0x2C, 0x76, 0xE3, 0x0D,
  0x68, 0x9E, 0x06, 0xD4, 0xBD, 0x26, 0xDD, 0x92, 0x59, 0x13, 0x84, 0xF3, 0xC7, 0x38, 0x7E, 0xC8,
  0x6C, 0x2C, 0x74, 0x6A, 0x2D, 0x4B, 0x7F, 0x07, 0x83, 0x4B, 0xC8, 0x93, 0x28, 0xD0, 0xF6, 0x32,
  0xC6, 0x27, 0xF5, 0x05, 0xC6, 0x46, 0x2C, 0x72, 0x6A, 0x43, 0xA4, 0x58, 0x67, 0xB6, 0x18, 0x2F,
  0x90, 0xA6, 0x5D, 0x36, 0xBB, 0x91, 0xB7, 0x82, 0x48, 0x14, 0x70, 0x2C, 0x75, 0x2D, 0x0D, 0x4A,
  0xB4, 0xAD, 0x46, 0x49, 0x27, 0x4A, 0xEB, 0x33, 0x10, 0x36, 0x3C, 0x0D, 0x48, 0x21, 0xB3, 0x50,
  0x2C, 0x73, 0x2D, 0xC0, 0x97, 0xC4, 0x5F, 0x31, 0x5D, 0x3B, 0x45, 0x13, 0xB0, 0x1B, 0xF2, 0xE7,
  0xC4, 0xD6, 0x15, 0xFA, 0xB6, 0x2C, 0x75, 0x2D, 0x0F, 0x2D, 0x01, 0x1F, 0x8E, 0x88, 0x82, 0xBD,
  0xB4, 0xD5, 0x8C, 0x94, 0x27, 0xD6, 0xB1, 0xC6, 0xE1, 0xAA, 0x2C, 0x41, 0x9D, 0x8E, 0x1F, 0xCA,
  0xD5, 0xF6, 0x1A, 0x18, 0xE3, 0x2A, 0xF7, 0x75, 0x8F, 0x06, 0xCE, 0x24, 0x0D, 0x89, 0x14, 0x2C,
  0x24, 0x4F, 0x9C, 0x1E, 0x00, 0x01, 0xB6, 0x31, 0x27, 0x47, 0xD9, 0x34, 0x81, 0x66, 0xF1, 0x71,
  0x32, 0xEC, 0x2B, 0x0E, 0x2C, 0x43, 0xB5, 0x8E, 0x00, 0x22, 0x11, 0x36, 0xB7, 0x8A, 0x06, 0x22,
  0x4A, 0x14, 0x51, 0x9F, 0xB2, 0x3D, 0x06, 0x9E, 0xDC, 0x2C, 0xD1, 0xCD, 0x7C, 0x00, 0x0E, 0x68,
  0xEF, 0xE0, 0x9B, 0x27, 0x80, 0x1D, 0xC0, 0x23, 0xFF, 0xEB, 0xA0, 0x82, 0x00, 0x00, 0x2C, 0x97,
  0x85, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x8A, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20,
  0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F,
  0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF,
  0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9,
  0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82,
  0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0,
  0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1,
  0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC,
  0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00,
  0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03,
  0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82,
  0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00,
  0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00,
  0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF,
  0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66,
  0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F,
  0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C,
  0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8,
  0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00,
  0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9,
  0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5,
  0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20,
  0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F,
  0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF,
  0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9,
  0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82,
  0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0,
  0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1,
  0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC,
  0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00,
  0x00, 0x2C, 0x84, 0x00, 0x8E, 0x84, 0x7C, 0x41, 0x29, 0xE9, 0xBA, 0x0F, 0x8A, 0x7B, 0x01, 0x95,
  0x93, 0xE8, 0x46, 0x05, 0xE6, 0xC4, 0x2C, 0x4C, 0xB0, 0x9A, 0x0D, 0x20, 0x89, 0xE3, 0x7E, 0x56,
  0x12, 0xF7, 0xDD, 0xFE, 0xED, 0x4F, 0x1E, 0x3D, 0x7C, 0x4C, 0x10, 0x2C, 0xA7, 0x0D, 0x8E, 0x1E,
  0x80, 0xCE, 0x36, 0x00, 0xE2, 0x1B, 0x2F, 0xBD, 0x82, 0x70, 0xF9, 0x04, 0x47, 0x5E, 0x5F, 0x10,
  0x2C, 0x06, 0x75, 0x11, 0x69, 0xBB, 0xB0, 0x38, 0xFD, 0x14, 0x30, 0xAD, 0xAC, 0x34, 0x81, 0x4D,
  0x3F, 0x90, 0xD3, 0x74, 0x3E, 0x2C, 0x2B, 0xF9, 0x1F, 0xE0, 0xDF, 0xA1, 0x8E, 0x02, 0xC1, 0x3F,
  0x49, 0x06, 0xE7, 0x21, 0xC3, 0xAF, 0x40, 0x41, 0xFE, 0xA4, 0x2C, 0x30, 0x74, 0xED, 0xE1, 0x5E,
  0x61, 0x9E, 0x09, 0x87, 0xE1, 0x0A, 0x8D, 0x9C, 0xD9, 0x53, 0x49, 0xAE, 0xA1, 0x22, 0x0A, 0x2C,
  0x30, 0x74, 0x4F, 0xE9, 0x5E, 0xA1, 0x9C, 0xA3, 0xBB, 0xEB, 0x9B, 0xE8, 0x22, 0x92, 0xC7, 0x95,
  0x42, 0x7E, 0xE6, 0xDC, 0x2C, 0x3D, 0x70, 0xC5, 0xE3, 0x1F, 0xE1, 0x99, 0xFB, 0xF5, 0x1B, 0x3E,
  0xF4, 0x16, 0xB0, 0xC9, 0x2B, 0xC8, 0xF1, 0x86, 0x42, 0x2C, 0x3C, 0xE5, 0x25, 0xE0, 0xFE, 0x01,
  0x93, 0x50, 0xD4, 0xF5, 0xFE, 0xC4, 0x59, 0x9F, 0x46, 0xA0, 0x2E, 0x4E, 0x20, 0xA6, 0x2C, 0x34,
  0xFA, 0x9B, 0xE1, 0x98, 0x41, 0x81, 0xE6, 0x75, 0x52, 0x7F, 0x10, 0xB5, 0xFA, 0xA4, 0xC5, 0x2D,
  0x5F, 0x83, 0xC8, 0x2C, 0x24, 0x10, 0x8E, 0x1F, 0xA0, 0x01, 0x9E, 0xA0, 0xA2, 0x01, 0x9C, 0xEC,
  0x99, 0xC7, 0x59, 0xAA, 0x60, 0x23, 0xCA, 0x74, 0x2C, 0x3B, 0x8C, 0xBE, 0x1E, 0x01, 0xE0, 0x79,
  0xF5, 0x06, 0xC0, 0x8E, 0x82, 0xB1, 0xF7, 0x76, 0x98, 0x87, 0x3D, 0x87, 0xC6, 0x2C, 0x62, 0xA8,
  0x40, 0x5E, 0xC6, 0x6A, 0xC3, 0x73, 0x3E, 0x7B, 0xCE, 0x7B, 0x18, 0xF8, 0x9B, 0x1F, 0x5D, 0xC2,
  0x79, 0x0A, 0x2C, 0xDD, 0xFA, 0x2C, 0xF1, 0x21, 0xA5, 0x87, 0x08, 0x50, 0xF6, 0x58, 0x92, 0x2B,
  0x5E, 0x85, 0xE8, 0x1C, 0xB5, 0x93, 0xA2, 0x2C, 0xBE, 0x14, 0x2C, 0x79, 0x80, 0xF7, 0x11, 0x5F,
  0xB8, 0xF7, 0x88, 0x89, 0xCF, 0xB1, 0xAD, 0x96, 0xA8, 0x57, 0xFA, 0x5C, 0x2C, 0x42, 0x15, 0xC1,
  0x69, 0x81, 0x0A, 0x09, 0xCF, 0xCB, 0xEC, 0x6A, 0xB2, 0x72, 0xE9, 0xB9, 0xB9, 0x91, 0x4F, 0xE6,
  0xF0, 0x2C, 0x6D, 0xAC, 0x37, 0x78, 0x93, 0xE0, 0x00, 0x07, 0xED, 0xB3, 0x4B, 0x93, 0xDC, 0xC7,
  0x6B, 0x1B, 0x20, 0xA6, 0x54, 0xF4, 0x2C, 0x55, 0x9D, 0x78, 0xF1, 0x0F, 0x00, 0x00, 0x0D, 0xE0,
  0xCF, 0x31, 0xC9, 0x0F, 0xE3, 0xC2, 0x84, 0x60, 0xD9, 0x9F, 0xFA, 0x2C, 0x36, 0xF3, 0x9D, 0x4A,
  0xB4, 0xA0, 0x18, 0x7A, 0xA6, 0x47, 0xAA, 0x09, 0x18, 0x07, 0x4A, 0x66, 0x5C, 0x44, 0x6C, 0x92,
  0x2C, 0x25, 0x7C, 0x9C, 0xB5, 0x1F, 0xC0, 0x31, 0x9D, 0x1F, 0x68, 0x2E, 0xA8, 0x92, 0xCA, 0x4A,
  0xFB, 0x09, 0x84, 0x78, 0x62, 0x2C, 0x24, 0x4B, 0x8F, 0x2D, 0xFD, 0xA0, 0x61, 0x8C, 0xB8, 0x5C,
  0xCC, 0x61, 0x18, 0x53, 0x56, 0x7C, 0x0C, 0x19, 0x6D, 0x38, 0x2C, 0x1D, 0x9A, 0x40, 0x97, 0x76,
  0x80, 0x61, 0xB5, 0xC6, 0xB7, 0xDE, 0x0F, 0xE4, 0xEF, 0x25, 0x5C, 0x19, 0x56, 0x1B, 0x4C, 0x2C,
  0x1C, 0x08, 0x8E, 0x1F, 0xD0, 0x0A, 0xFE, 0x8E, 0x82, 0xB2, 0x1B, 0xE8, 0x39, 0x95, 0x6A, 0x29,
  0x9A, 0x21, 0x72, 0x3E, 0x2C, 0x24, 0x4A, 0x4E, 0x1E, 0xF6, 0xE0, 0x79, 0xE4, 0x16, 0xBF, 0xB6,
  0xC2, 0x3C, 0x6F, 0xA2, 0x89, 0x88, 0x70, 0xB8, 0x42, 0x2C, 0x2E, 0xED, 0x9C, 0xD2, 0x37, 0xC0,
  0xD3, 0x4D, 0x0F, 0x3F, 0xA3, 0xEC, 0xC9, 0x04, 0xB9, 0x06, 0xFE, 0xC1, 0x38, 0x50, 0x2C, 0x38,
  0xED, 0x9C, 0x96, 0x5F, 0xC1, 0x8E, 0x07, 0x36, 0x7B, 0xB7, 0x69, 0x65, 0x63, 0x43, 0xD6, 0xE5,
  0xB8, 0xD6, 0x6C, 0x2C, 0x55, 0x7D, 0xB5, 0xE1, 0x1F, 0xC1, 0xEE, 0x05, 0xBE, 0x5F, 0x01, 0xAE,
  0xC8, 0x16, 0x9A, 0xC6, 0xCD, 0x0C, 0xBB, 0x54, 0x2C, 0x65, 0x7D, 0x2D, 0xE0, 0x4F, 0xC6, 0x0E,
  0x19, 0x40, 0xA7, 0x00, 0x38, 0xBC, 0x85, 0x8C, 0xC1, 0x07, 0x6A, 0x5D, 0x4E, 0x2C, 0x65, 0x9C,
  0x8E, 0xF1, 0x92, 0xC6, 0x6E, 0x12, 0x58, 0x07, 0xCB, 0x32, 0x89, 0x09, 0x8C, 0x71, 0x72, 0xEF,
  0x5C, 0xB8, 0x2C, 0x6A, 0xE4, 0x8F, 0x68, 0x9E, 0x26, 0xD6, 0x1E, 0x09, 0x4F, 0x88, 0x43, 0x92,
  0x71, 0xC3, 0xC7, 0xB6, 0xC9, 0x43, 0x06, 0x2C, 0x72, 0x6A, 0x2D, 0x68, 0x9F, 0x07, 0x83, 0x5B,
  0xC8, 0x12, 0x2D, 0x58, 0x1A, 0xB6, 0x66, 0xC4, 0x1D, 0x49, 0x3D, 0x06, 0x2C, 0x77, 0xE4, 0x2D,
  0x4A, 0xFE, 0x47, 0x9E, 0x12, 0xB0, 0xD9, 0x88, 0x76, 0x6F, 0x8E, 0x64, 0xD9, 0xD8, 0x04, 0xB2,
  0xCE, 0x2C, 0x75, 0x2D, 0x42, 0xD3, 0x25, 0xA7, 0xEC, 0xA0, 0xA7, 0xF7, 0x9F, 0xA7, 0x98, 0xD3,
  0xC8, 0x98, 0x1B, 0x74, 0x9A, 0x3A, 0x2C, 0x73, 0x2D, 0x8E, 0x5B, 0xC5, 0x3A, 0x23, 0x3F, 0x19,
  0x54, 0x51, 0x88, 0x43, 0x64, 0xDE, 0xBF, 0x14, 0x65, 0x83, 0x0E, 0x2C, 0x75, 0x2D, 0x8E, 0xD2,
  0x08, 0x15, 0x8B, 0xB4, 0x61, 0x52, 0x9B, 0x4B, 0x01, 0xDA, 0x7A, 0xB2, 0x9C, 0x54, 0x7E, 0x16,
  0x2C, 0x49, 0x9D, 0xB0, 0x1E, 0xE2, 0x15, 0xFC, 0x1A, 0x46, 0xBC, 0xAD, 0x56, 0x5D, 0x30, 0x2C,
  0x45, 0x59, 0x56, 0xBE, 0x50, 0x2C, 0x27, 0x50, 0x9C, 0x17, 0x91, 0x01, 0xCB, 0xFF, 0xA6, 0xF1,
  0xCB, 0xB9, 0x29, 0xFE, 0xA6, 0x64, 0x45, 0xF0, 0x81, 0x30, 0x2C, 0x44, 0x26, 0x8E, 0x00, 0x80,
  0x0B, 0x9F, 0xFA, 0xCA, 0x03, 0x12, 0x9C, 0x4F, 0x92, 0x07, 0x32, 0x00, 0x54, 0xEF, 0x04, 0x2C,
  0xD0, 0x86, 0x7C, 0x00, 0x06, 0x79, 0xFF, 0xE1, 0x9A, 0x66, 0x01, 0x9D, 0xF2, 0x13, 0xFF, 0xEA,
  0x9C, 0x82, 0x08, 0x08, 0x2C, 0x97, 0x85, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x8A, 0x66, 0x00,
  0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9,
  0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5,
  0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20,
  0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F,
  0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF,
  0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9,
  0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82,
  0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0,
  0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1,
  0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC,
  0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00,
  0x00, 0x2C, 0xD1, 0xA9, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82, 0x66, 0x00, 0x1F, 0xC0, 0x03,
  0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00, 0x2C, 0xC5, 0x1A, 0xCC, 0x00, 0x1F, 0xF9, 0xFF, 0xE1, 0x82,
  0x66, 0x00, 0x1F, 0xC0, 0x03, 0xFF, 0xE8, 0x20, 0x82, 0x00, 0x00
};

int audio_StartAlarmSound(void)
{
    eat_audio_play_data(audio_Alarm, sizeof(audio_Alarm), EAT_AUDIO_FORMAT_AMR, EAT_AUDIO_PLAY_ONCE, 15, EAT_AUDIO_PATH_SPK1);
    return 0;
}

int audio_bluetoothFoundSound(void)
{
    if(MED_AUDIO_SUCCESS != eat_audio_play_file(AUDIO_FILE_NAME_FOUND, EAT_FALSE, NULL, 15, EAT_AUDIO_PATH_SPK1))
    {
        eat_audio_play_data(audio_BluetoothFound_Source, sizeof(audio_BluetoothFound_Source), EAT_AUDIO_FORMAT_AMR, EAT_AUDIO_PLAY_ONCE, 15, EAT_AUDIO_PATH_SPK1);
    }
    return 0;
}

int audio_bluetoothLostSound(void)
{
    if(MED_AUDIO_SUCCESS != eat_audio_play_file(AUDIO_FILE_NAME_LOST, EAT_FALSE, NULL, 15, EAT_AUDIO_PATH_SPK1))
    {
        eat_audio_play_data(audio_BluetoothLost_Source, sizeof(audio_BluetoothLost_Source), EAT_AUDIO_FORMAT_AMR, EAT_AUDIO_PLAY_ONCE, 15, EAT_AUDIO_PATH_SPK1);
    }
    return 0;
}

int audio_stopSound(void)
{
    if(EAT_TRUE != eat_audio_stop_data())
    {
        eat_audio_stop_file();
    }
    return 0;
}

