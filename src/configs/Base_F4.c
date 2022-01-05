/*******************************************************************************
    CANopen Object Dictionary definition for CANopenNode V4

    This file was automatically generated by CANopenEditor v4.0-51-g2d9b1ad

    https://github.com/CANopenNode/CANopenNode
    https://github.com/CANopenNode/CANopenEditor

    DON'T EDIT THIS FILE MANUALLY, UNLESS YOU KNOW WHAT YOU ARE DOING !!!!
*******************************************************************************/

#define OD_DEFINITION
#include "301/CO_ODinterface.h"
#include "Base_F4.h"

#if CO_VERSION_MAJOR < 4
#error This Object dictionary is compatible with CANopenNode V4.0 and above!
#endif

/*******************************************************************************
    OD data initialization of all groups
*******************************************************************************/
Base_F4_ATTR_RAM Base_F4_RAM_t Base_F4_RAM = {
    .x6000_moduleMCU = {
        .highestSub_indexSupported = 0x03,
        .family = {'S', 'T', 'M', '3', '2', 'F', '4', 0},
        .board = {'S', 'T', 'M', 'F', '3', '2', '4', '0', '7', 0}
    },
    .x6100_moduleCAN_1 = {
        .highestSub_indexSupported = 0x07,
        .disabled = 0x00000000,
        .TX_Port = 0x01,
        .TX_Pin = 0x0B,
        .RX_Port = 0x01,
        .RX_Pin = 0x0C,
        .RX_Pin = 0x0C
    },
    .x6200_I2C_EEPROM = {
        .highestSub_indexSupported = 0x02,
        .transportIndex = 0x7600,
        .transportAddress = 0x0000
    }
};



/*******************************************************************************
    All OD objects (constant definitions)
*******************************************************************************/
typedef struct {
    OD_obj_record_t o_6000_moduleMCU[3];
    OD_obj_record_t o_6100_moduleCAN_1[7];
    OD_obj_record_t o_6200_I2C_EEPROM[3];
} Base_F4Objs_t;

static CO_PROGMEM Base_F4Objs_t Base_F4Objs = {
    .o_6000_moduleMCU = {
        {
            .dataOrig = &Base_F4_RAM.x6000_moduleMCU.highestSub_indexSupported,
            .subIndex = 0,
            .attribute = ODA_SDO_R,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6000_moduleMCU.family[0],
            .subIndex = 2,
            .attribute = ODA_SDO_RW | ODA_STR,
            .dataLength = 7
        },
        {
            .dataOrig = &Base_F4_RAM.x6000_moduleMCU.board[0],
            .subIndex = 3,
            .attribute = ODA_SDO_RW | ODA_STR,
            .dataLength = 9
        }
    },
    .o_6100_moduleCAN_1 = {
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.highestSub_indexSupported,
            .subIndex = 0,
            .attribute = ODA_SDO_R,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.disabled,
            .subIndex = 1,
            .attribute = ODA_SDO_RW | ODA_MB,
            .dataLength = 4
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.TX_Port,
            .subIndex = 2,
            .attribute = ODA_SDO_RW,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.TX_Pin,
            .subIndex = 3,
            .attribute = ODA_SDO_RW,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.RX_Port,
            .subIndex = 5,
            .attribute = ODA_SDO_RW,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.RX_Pin,
            .subIndex = 6,
            .attribute = ODA_SDO_RW,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6100_moduleCAN_1.RX_Pin,
            .subIndex = 7,
            .attribute = ODA_SDO_RW,
            .dataLength = 1
        }
    },
    .o_6200_I2C_EEPROM = {
        {
            .dataOrig = &Base_F4_RAM.x6200_I2C_EEPROM.highestSub_indexSupported,
            .subIndex = 0,
            .attribute = ODA_SDO_R,
            .dataLength = 1
        },
        {
            .dataOrig = &Base_F4_RAM.x6200_I2C_EEPROM.transportIndex,
            .subIndex = 1,
            .attribute = ODA_SDO_RW | ODA_MB,
            .dataLength = 2
        },
        {
            .dataOrig = &Base_F4_RAM.x6200_I2C_EEPROM.transportAddress,
            .subIndex = 2,
            .attribute = ODA_SDO_RW | ODA_MB,
            .dataLength = 2
        }
    }
};


/*******************************************************************************
    Object dictionary
*******************************************************************************/
static Base_F4_ATTR_OD OD_entry_t Base_F4List[] = {
    {0x6000, 0x03, ODT_REC, &Base_F4Objs.o_6000_moduleMCU, NULL},
    {0x6100, 0x07, ODT_REC, &Base_F4Objs.o_6100_moduleCAN_1, NULL},
    {0x6200, 0x03, ODT_REC, &Base_F4Objs.o_6200_I2C_EEPROM, NULL},
    {0x0000, 0x00, 0, NULL, NULL}
};

static OD_t _Base_F4 = {
    (sizeof(Base_F4List) / sizeof(Base_F4List[0])) - 1,
    &Base_F4List[0]
};

OD_t *Base_F4 = &_Base_F4;
