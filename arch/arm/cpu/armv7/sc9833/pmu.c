/******************************************************************************
 ** File Name:      pmu.c                                             *
 ** Author:         Zhongfa.Wang                                              *
 ** DATE:           26/12/2016                                                *
 ** Copyright:      2014 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:    This file defines the basic information on chip.          *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 26/12/2016     Zhongfa.Wang		Create.                                   *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include <asm/io.h>
#include "adi_hal_internal.h"
//#include "asm/arch/wdg_drvapi.h"
#include "asm/arch/sprd_reg.h"
#include "asm/arch-sc9833/common.h"
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
extern   "C"
{
#endif

#ifndef CONFIG_FPGA
void pmu_commom_config(void)
{
	uint32_t reg_val;

	CHIP_REG_SET(REG_PMU_APB_PD_CA7_TOP_CFG,
		//BIT_PMU_APB_PD_CA7_TOP_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_TOP_PD_SEL |
		//BIT_PMU_APB_PD_CA7_TOP_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CA7_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_TOP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_CA7_TOP_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_CA7_TOP_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA7_C0_CFG,
		//BIT_PMU_APB_PD_CA7_C0_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA7_C0_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C0_PD_SEL |
		//BIT_PMU_APB_PD_CA7_C0_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CA7_C0_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C0_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_CA7_C0_PWR_ON_SEQ_DLY(0x10) |
		BIT_PMU_APB_PD_CA7_C0_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA7_C1_CFG,
		//BIT_PMU_APB_PD_CA7_C1_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA7_C1_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C1_PD_SEL |
		BIT_PMU_APB_PD_CA7_C1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CA7_C1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C1_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_CA7_C1_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_CA7_C1_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA7_C2_CFG,
		//BIT_PMU_APB_PD_CA7_C2_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA7_C2_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C2_PD_SEL |
		BIT_PMU_APB_PD_CA7_C2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CA7_C2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C2_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_CA7_C2_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_CA7_C2_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA7_C3_CFG,
		//BIT_PMU_APB_PD_CA7_C3_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA7_C3_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C3_PD_SEL |
		BIT_PMU_APB_PD_CA7_C3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CA7_C3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA7_C3_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_CA7_C3_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_CA7_C3_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA7_TOP_CFG2,
		BIT_PMU_APB_PD_CA7_TOP_DCDC_PWR_ON_DLY(0x0a) |
		BIT_PMU_APB_PD_CA7_TOP_DCDC_PWR_OFF_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AP_SYS_CFG,
		//BIT_PMU_APB_PD_AP_SYS_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_AP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_AP_SYS_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_MM_TOP_CFG,
		//BIT_PMU_APB_PD_MM_TOP_FORCE_SHUTDOWN |
		//BIT_PD_MM_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_MM_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_MM_TOP_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_TOP_CFG,
		//BIT_PMU_APB_PD_GPU_TOP_FORCE_SHUTDOWN |
		//BIT_PD_GPU_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GPU_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_GPU_TOP_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TD_CFG,
		BIT_PMU_APB_PD_WTLCP_TD_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TD_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TD_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_TD_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_TD_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P1_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P2_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_LDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_LDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_WTLCP_LDSP_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TGDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_TGDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_TGDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TGDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_SEQ_DLY(0x04) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_A_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_A_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_B_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_B_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_SYS_CFG,
		BIT_PMU_APB_PD_WTLCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_SYS_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_PUBCP_SYS_CFG,
		//BIT_PMU_APB_PD_PUBCP_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_PUBCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_PUBCP_SYS_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P3_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P4_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P4_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P4_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P4_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_P4_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_WTLCP_LTE_P4_ISO_ON_DLY(0x00) |
		0
	);
	/*PUB_SYS for DDR*/
	reg_val = CHIP_REG_GET(REG_PMU_APB_PD_PUB_SYS_CFG) & 0xff000000;
	CHIP_REG_SET(REG_PMU_APB_PD_PUB_SYS_CFG,
		//BIT_PMU_APB_PD_PUB_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_PUB_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUB_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_PUB_SYS_PWR_ON_SEQ_DLY(0x00) |
		BIT_PMU_APB_PD_PUB_SYS_ISO_ON_DLY(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTL_WAIT_CNT,
		BIT_PMU_APB_XTL1_WAIT_CNT(0x40) |
		BIT_PMU_APB_XTL0_WAIT_CNT(0x40) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF_WAIT_CNT,
		BIT_PMU_APB_XTLBUF1_WAIT_CNT(0x07) |
		BIT_PMU_APB_XTLBUF0_WAIT_CNT(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT1,
		BIT_PMU_APB_LTEPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_TWPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_DPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_MPLL_WAIT_CNT(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT2,
		BIT_PMU_APB_CPPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_RPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_GPLL_WAIT_CNT(0x07) |
		BIT_PMU_APB_LVDSDIS_PLL_WAIT_CNT(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG0,
		BIT_PMU_APB_PUBCP_PWR_WAIT_CNT(0x00) |
		BIT_PMU_APB_WTLCP_PWR_WAIT_CNT(0x00) |
		BIT_PMU_APB_AP_PWR_WAIT_CNT(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG1,
		BIT_PMU_APB_ARM7_PWR_WAIT_CNT(0x00) |
		0
	);
}

/*deep_sleep: 0.8V, normal: 1.05V; OD: 1.2V*/
static void dcdc_core_ds_config(uint32_t core_cal_para, uint32_t core_ctrl_para)
{
	ANA_REG_SET(ANA_REG_GLB_DCDC_CORE_SLP_CTRL1,
			BITS_DCDC_CORE_CAL_DS_SW(core_cal_para)|
			BITS_DCDC_CORE_CTRL_DS_SW(core_ctrl_para)
	);
}

static void clk_auto_gate_enable(void)
{
       /* Set 0x20e00060~0x20e0009C as 0x500ff */
       /* AP main matrix LPC */
       CHIP_REG_SET(REG_AP_AHB_M0_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M1_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M2_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M3_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M4_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M5_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M6_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M7_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M8_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_M9_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_MAIN_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_S0_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_S1_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_S2_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_S3_LPC,0x500ff);
       CHIP_REG_SET(REG_AP_AHB_S4_LPC,0x500ff);

       /* SET BIT[18,16] */
       /* TOP reg slice LPC */
       CHIP_REG_OR(REG_AON_APB_TOP_LPC0,BIT_AON_APB_TOP_LPC0_ACTIVE_SYNC_SEL | BIT_AON_APB_TOP_LPC0_EB);
       CHIP_REG_OR(REG_AON_APB_TOP_LPC1,BIT_AON_APB_TOP_LPC1_ACTIVE_SYNC_SEL | BIT_AON_APB_TOP_LPC1_EB);
       CHIP_REG_OR(REG_AON_APB_TOP_LPC2,BIT_AON_APB_TOP_LPC2_ACTIVE_SYNC_SEL | BIT_AON_APB_TOP_LPC2_EB);
       CHIP_REG_OR(REG_AON_APB_TOP_LPC3,BIT_AON_APB_TOP_LPC3_ACTIVE_SYNC_SEL | BIT_AON_APB_TOP_LPC3_EB);

       /* SET BIT[19:16] as 0xC [3:0] as 0xF */
       /* EMC CLK AUTO GATE Enable  */
	   CHIP_REG_OR(REG_AON_APB_EMC_AUTO_GATE_EN,BIT_AON_APB_PUBCP_PUB_AUTO_GATE_EN | BIT_AON_APB_WTLCP_PUB_AUTO_GATE_EN);

       /* SET BIT[1] */
       /* WCDMA CLK AUTO GATE Enable */
	   CHIP_REG_OR(REG_AON_APB_GLB_WCDMA_CTRL,BIT_AON_APB_PUBCP_WCDMA_AUTO_GATE_EN);

	/* Config AON DMA Lightsleep Enable */
	CHIP_REG_OR(REG_PMU_APB_LIGHT_SLEEP_ENABLE,BIT_PMU_APB_AON_DMA_LSLP_ENA | BIT_PMU_APB_DMA_CHNALL_LSLP_ENA);
	CHIP_REG_AND(REG_PMU_APB_SLEEP_CTRL,~BIT_PMU_APB_AON_DMA_FORCE_LIGHT_SLEEP);
}


void CSP_Init(uint32_t gen_para)
{
	//uint32_t reg_val;
	pmu_commom_config();
	dcdc_core_ds_config(0,4);
	clk_auto_gate_enable();
}
#endif

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


