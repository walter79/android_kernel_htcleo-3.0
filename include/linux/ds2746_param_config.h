/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 2010 High Tech Computer Corporation

Module Name:

		ds2746_param_config.c

Abstract:

		This module tells batt_param.c module what the battery characteristic is.
		And also which charger/gauge component hardware uses, to decide if software/hardware function is available.

Original Auther:

		Andy.ys Wang June-01-2010

---------------------------------------------------------------------------------*/


#ifndef __BATT_PARAM_CONFIG_H__
#define __BATT_PARAM_CONFIG_H__
#define HTC_BATT_BOARD_NAME "ACE"

/*========================================================================================

battery parameter defines (depend on board design)

========================================================================================*/

static BOOL support_ds2746_gauge_ic = TRUE;

UINT32 ID_RANGE[] =
{
  /* id resister range = [min, max)*/
  7150, 15500,   /* Sony 1300mAh (Formosa) */    /* 7.1k~15k */
  27500, 49500,   /* Sony 1300mAh (HTE) */  	  /* 28k~49.5k */
  15500, 27500,   /* Sanyo 1300mAh (HTE) */ 	  /* 16k~27k */
  100, 7150,   /* Samsung 1230mAh */  	 /* 0.1k~7k */
  0, 100,   /* HTC Extended 2300mAh */  	 /* 0k~0.1k */
};

/*This table is calculated according to temp formula for temp mapping.
If temp_adc is located on 0-95, then the temp_01c is 700.
			  96-99, then the temp_01c is 690.
			  100-102, then the temp_01c is 680.
			  ...
			  1117777777-1145, then the temp_01c is 0.
			  1146-1175, then the temp_01c is -1.
			  ...
			  1433-2046, then the temp_01c is -11.
*/
UINT32 TEMP_MAP_300K_100_4360[] =
{
0, 96, 100, 103, 107, 111, 115, 119, 123, 127,
133, 137, 143, 148, 154, 159, 165, 172, 178, 185,
192, 199, 207, 215, 223, 232, 241, 250, 260, 270,
280, 291, 301, 314, 326, 339, 352, 366, 380, 394,
410, 425, 442, 458, 476, 494, 512, 531, 551, 571,
592, 614, 636, 659, 682, 706, 730, 755, 780, 806,
833, 860, 887, 942, 943, 971, 1000, 1028, 1058, 1087,
1117, 1146, 1176, 1205, 1234, 1264, 1293, 1321, 1350, 1378,
1406, 1433, 2047,
};

UINT32 TEMP_MAP_300K_47_3440[] =
{
0, 68, 70, 72, 74, 76, 79, 81, 84, 86,
89, 92, 95, 97, 101, 104, 107, 110, 114, 118,
121, 125, 129, 133, 138, 142, 147, 152, 157, 162,
167, 173, 178, 184, 191, 197, 204, 210, 218, 225,
232, 240, 249, 257, 266, 275, 284, 294, 303, 314,
324, 335, 346, 358, 370, 382, 395, 408, 422, 436,
450, 465, 480, 496, 513, 529, 546, 564, 582, 601,
620, 639, 659, 680, 701, 722, 744, 766, 788, 811,
835, 858, 2047,
};

UINT32 TEMP_MAP_1000K_100_4360[] =
{
0, 30, 31, 32, 34, 35, 36, 38, 39, 40,
42, 44, 45, 47, 49, 51, 53, 55, 57, 60,
62, 64, 67, 70, 73, 76, 79, 82, 86, 89,
93, 97, 101, 106, 111, 115, 120, 126, 131, 137,
143, 150, 156, 163, 171, 178, 187, 195, 204, 213,
223, 233, 244, 255, 267, 279, 292, 306, 320, 334,
350, 365, 382, 399, 418, 436, 456, 476, 497, 519,
542, 566, 590, 615, 641, 668, 695, 723, 752, 782,
812, 843, 2047,
};

UINT32 *TEMP_MAP = TEMP_MAP_300K_100_4360;

/* use default parameter if it doesn't be passed from board */
#define PD_M_COEF_DEFAULT	(30)
#define PD_M_RESL_DEFAULT	(100)
#define PD_T_COEF_DEFAULT	(250)
#define CAPACITY_DEDUCTION_DEFAULT	(0)

UINT32 FL_25[] =
{
  2300,   /* Unknown battery */
  1280,   /* Sony 1300mAh (Formosa) */
  1280,   /* Sony 1300mAh (HTE) */
  1250,   /* Sanyo 1300mAh (HTE) */
  1230,   /* Samsung 1230mAh */
  2300,  /* HTC Extended 2300mAh */
};

UINT32 PD_M_COEF[] =
{
  /* for TAO PMA, this is defined as PD_M; for TPE PMA, this is defined as FT or t*/
  24, 	/* Unknown battery */
  24, 	/* Sony 1300mAh (Formosa) */
  24, 	/* Sony 1300mAh (HTE) */
  27, 	/* Sanyo 1300mAh (HTE) */
  30,  /* Samsung 1230mAh */
  30,  /* HTC Extended 2300mAh */ 
};

UINT32 PD_M_RESL[] =
{
  /* for TAO PMA, this is defined as PD_M; for TPE PMA, this is defined as FT or t*/
  100,	/* Unknown battery */
  100,	/* Sony 1300mAh (Formosa) */
  100,	/* Sony 1300mAh (HTE) */
  100,	/* Sanyo 1300mAh (HTE) */
  100,  /* Samsung 1230mAh */
  100,  /* HTC Extended 2300mAh */ 
};

UINT32 PD_T_COEF[] =
{
  /* Ex: 140 -> 0.014, 156 -> 0.0156*/
  140,	/* Unknown battery */
  140,	/* Sony 1300mAh (Formosa) */
  140,	/* Sony 1300mAh (HTE) */
  156,	/* Sanyo 1300mAh (HTE) */
  250,	/* Samsung 1230mAh */
  250,  /* HTC Extended 2300mAh */ 
};

/*! star_lee 20100426 - update KADC discharge parameter */
UINT32 M_PARAMETER_SONY_1300MAH_FORMOSA[] =
{
  /* capacity (in 0.01%) -> voltage (in mV)*/
  10000, 4100, 5500, 3839, 2400, 3759, 400, 3667, 0, 3397,
};

UINT32 M_PARAMETER_DEFAULT[] =
{
  /* capacity (in 0.01%) -> voltage (in mV)*/
  10000, 4135, 7500, 3960, 4700, 3800, 1700, 3727, 900, 3674, 300, 3640, 0, 3420,
};

UINT32 M_PARAMETER_Samsung_1230MAH_FORMOSA[] =
{
  /* capacity (in 0.01%) -> voltage (in mV)*/
  10000, 4135, 7500, 3960, 4700, 3800, 1700, 3727, 900, 3674, 300, 3640, 0, 3420,
};

UINT32 M_PARAMETER_HTC_2300MAH_FORMOSA[] =
{
  /* capacity (in 0.01%) -> voltage (in mV)*/
  10000, 4135, 7500, 3960, 4700, 3800, 1700, 3727, 900, 3674, 300, 3640, 0, 3420,
};


UINT32 *M_PARAMTER_TABLE[] =
{
  /* Unknown battery */
  (UINT32 *) (M_PARAMETER_SONY_1300MAH_FORMOSA),
  /* same as Sony 1300mAh (Formosa) currently... */
  /* Sony 1300mAh (Formosa) */
  (UINT32 *) (M_PARAMETER_SONY_1300MAH_FORMOSA),
  /* Sony 1300mAh (HTE) */
  (UINT32 *) (M_PARAMETER_SONY_1300MAH_FORMOSA),
  /* same as Sony 1300mAh (Formosa) currently... */
  /* Sanyo 1300mAh (HTE) */
  (UINT32 *) (M_PARAMETER_SONY_1300MAH_FORMOSA),
  /* same as Sony 1300mAh (Formosa) currently... */
  /* Samsung 1230mAh */
  (UINT32 *) (M_PARAMETER_Samsung_1230MAH_FORMOSA),
  /* HTC Extended 2300mAh */
  (UINT32 *) (M_PARAMETER_HTC_2300MAH_FORMOSA),
};

INT32 TEMP_RANGE[] =
{
  /* mapping temp to temp_index*/
  200,  		  /* ~20C */
  100,  		  /* 20~10C  */
  50,   		  /* 10~5C */
  0,			  /* 5~0C */ -5,   		  /* 0~-5C */ -10, 		   /* -5~-10C */ -3000,
  /* -10C~ */
};

UINT32 *PD_M_COEF_TABLE_BOOT[] =
{
  /* mapping current to pd_m_coef table when booting*/
  (UINT32 *) (PD_M_COEF),		/* ~20C,	using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 20~10C,  using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 10~5C,   using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 5~0C,	using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 0~-5C,   using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* -5~-10C, using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* -10C~,   using PD_M_COEF */
};

UINT32 *PD_M_COEF_TABLE[] =
{
  /* mapping current to pd_m_coef table*/
  (UINT32 *) (PD_M_COEF),		/* ~20C,	using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 20~10C,  using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 10~5C,   using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 5~0C,	using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* 0~-5C,   using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* -5~-10C, using PD_M_COEF */
  (UINT32 *) (PD_M_COEF),		/* -10C~,   using PD_M_COEF */
};

UINT32 *PD_M_RESL_TABLE_BOOT[] =
{
  /* mapping current to pd_m_coef table when booting*/
  (UINT32 *) (PD_M_RESL),		/* ~20C,	using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 20~10C,  using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 10~5C,   using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 5~0C,	using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 0~-5C,   using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* -5~-10C, using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* -10C~,   using PD_M_RESL */
};

UINT32 *PD_M_RESL_TABLE[] =
{
  /* mapping current to pd_m_coef table*/
  (UINT32 *) (PD_M_RESL),		/* ~20C,	using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 20~10C,  using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 10~5C,   using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 5~0C,	using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* 0~-5C,   using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* -5~-10C, using PD_M_RESL */
  (UINT32 *) (PD_M_RESL),		/* -10C~,   using PD_M_RESL */
};

UINT32 CAPACITY_DEDUCTION_01p[] =
{
  0,  					  /* ~20C,    upper capacity 100 is usable */
  0,						/* 20~10C,  upper capacity 95 is usable */
  0,						/* 10~5C,   upper capacity 92 is usable */
  0,						/* 5~0C,	upper capacity 90 is usable */
  0,						/* 0~-5C,   upper capacity 87 is usable */
  0,						/* -5~-10C, upper capacity 85 is usable */
  0,						/* -10C~,   upper capacity 85 is usable */
};

/*========================================================================================

battery formula coef definition, can be re-programable

========================================================================================*/

/* adc converter*/

static INT32 voltage_adc_to_mv_coef = 244;
static INT32 voltage_adc_to_mv_resl = 100;
static INT32 current_adc_to_mv_coef = 625;
static INT32 current_adc_to_mv_resl = 1580;
static INT32 discharge_adc_to_mv_coef = 625;
static INT32 discharge_adc_to_mv_resl = 1580;
static INT32 acr_adc_to_mv_coef = 625;
static INT32 acr_adc_to_mv_resl = 1580;
static INT32 charge_counter_zero_base_mAh = 500;

static INT32 id_adc_overflow = 3067; /* 3067 < id_adc: rawdata overflow */
static INT32 id_adc_resl = 2047;
static INT32 temp_adc_resl = 2047;

/* kadc parameter*/

static INT32 pd_m_bias_mA;    /* the bias current when calculating pd_m*/

/* over temperature algorithm*/

static INT32 over_high_temp_lock_01c = 450;
static INT32 over_high_temp_release_01c = 420;
static INT32 over_low_temp_lock_01c; /*over_low_temp_lock_01c = 0*/
static INT32 over_low_temp_release_01c = 30;

/* function config*/

static BOOL is_allow_batt_id_change = TRUE;
extern BOOL is_need_battery_id_detection;


#define TEMP_MAX 70
#define TEMP_MIN -11
#define TEMP_NUM 83

#endif
