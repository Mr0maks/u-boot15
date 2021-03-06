#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include <adi_hal_internal.h>

/***************************************************************************************************************************/
/*     VDD18 VDD28 VDD25 RF0 RF1 RF2 EMMCIO EMMCCORE DCDCARM DCDCWRF DCDCWPA DCDCGEN DCDCOTP AVDD18 SD SIM0 SIM1 SIM2 CAMA */
/* AP    x     x    v     v   v   v     v      v        v       v       v       x       v      v    v    v   v     v    v  */
/* CP0   x     x    v     v   v   x     x      x        x       v       x       x       x      x    x    x   x     x    x  */
/* CP1   x     x    v     x   x   x     x      x        x       x       x       x       x      x    x    x   x     x    x  */
/* CP2   x     x    v     v   x   v     x      x        x       v       x       x       x      x    x    x   x     x    x  */
/* EX0   x     x    x     v   x   x     x      x        x       x       x       x       x      x    x    x   x     x    x  */
/* EX1   x     x    x     x   v   x     x      x        x       x       x       x       x      x    x    x   x     x    x  */
/* EX2   x     x    x     v   x   x     x      x        x       x       x       x       x      x    x    x   x     x    x  */
/***************************************************************************************************************************/

/***************************************************************************************************************************/
/*     CAMD CMAIO CAMMOT USB CLSG LPREF LPRF0 LPRF1 LPRF2 LPEMMCIO LPEMMCCORE LPWPA  LPGEN   LPARM LPMEM LPCORE LPBG  BG   */
/* AP    v     v    v     v   v   v     v      v     v       v       v          x       v      v     v     v     v     v   */
/* CP0   x     x    x     x   x   x     x      x     x       x       x          x       x      x     x     x     x     x   */
/* CP1   x     x    x     x   x   x     x      x     x       x       x          x       x      x     x     x     x     x   */
/* CP2   x     x    x     x   x   x     v      v     x       x       x          x       x      x     x     x     x     x   */
/* EX0   x     x    x     x   x   x     x      x     v       x       x          x       x      x     x     x     x     x   */
/* EX1   x     x    x     x   x   x     x      x     x       x       x          x       x      x     x     x     x     x   */
/* EX2   x     x    x     x   x   x     x      x     x       x       x          x       x      x     x     x     x     x   */
/***************************************************************************************************************************/
#if 0    //configured by SPL
void xtl_xtlbuf_sel_config(uint32_t gen_para)
{

	CHIP_REG_SET(REG_PMU_APB_XTL0_REL_CFG,
		BIT_PMU_APB_XTL0_CM3_SEL |
		BIT_PMU_APB_XTL0_AGCP_SEL |
		BIT_PMU_APB_XTL0_WTLCP_SEL |
		BIT_PMU_APB_XTL0_PUBCP_SEL |
		BIT_PMU_APB_XTL0_AP_SEL |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF0_REL_CFG,
		BIT_PMU_APB_XTLBUF0_CM3_SEL |
		BIT_PMU_APB_XTLBUF0_AGCP_SEL |
		BIT_PMU_APB_XTLBUF0_WTLCP_SEL |
		BIT_PMU_APB_XTLBUF0_PUBCP_SEL |
		BIT_PMU_APB_XTLBUF0_AP_SEL |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF1_REL_CFG,
		BIT_PMU_APB_XTLBUF1_CM3_SEL |
		BIT_PMU_APB_XTLBUF1_AGCP_SEL |
		BIT_PMU_APB_XTLBUF1_WTLCP_SEL |
		BIT_PMU_APB_XTLBUF1_PUBCP_SEL |
		BIT_PMU_APB_XTLBUF1_AP_SEL |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF2_REL_CFG,
		BIT_PMU_APB_XTLBUF2_CM3_SEL |
		BIT_PMU_APB_XTLBUF2_AGCP_SEL |
		BIT_PMU_APB_XTLBUF2_WTLCP_SEL |
		BIT_PMU_APB_XTLBUF2_PUBCP_SEL |
		BIT_PMU_APB_XTLBUF2_AP_SEL |
		0
	);
}
void pll_sel_config(uint32_t gen_para)
{
	CHIP_REG_SET(REG_PMU_APB_MPLL_REL_CFG,
		BIT_PMU_APB_MPLL1_CM3_SEL |
		BIT_PMU_APB_MPLL1_AGCP_SEL |
		BIT_PMU_APB_MPLL1_WTLCP_SEL |
		BIT_PMU_APB_MPLL1_PUBCP_SEL |
		BIT_PMU_APB_MPLL1_AP_SEL |
		BIT_PMU_APB_MPLL0_CM3_SEL |
		BIT_PMU_APB_MPLL0_AGCP_SEL |
		BIT_PMU_APB_MPLL0_WTLCP_SEL |
		BIT_PMU_APB_MPLL0_PUBCP_SEL |
		BIT_PMU_APB_MPLL0_AP_SEL |
		0
	);

	CHIP_REG_SET(REG_PMU_APB_DPLL_REL_CFG,
		BIT_PMU_APB_DPLL1_CM3_SEL |
		BIT_PMU_APB_DPLL1_AGCP_SEL |
		BIT_PMU_APB_DPLL1_WTLCP_SEL |
		BIT_PMU_APB_DPLL1_PUBCP_SEL |
		BIT_PMU_APB_DPLL1_AP_SEL |
		BIT_PMU_APB_DPLL0_CM3_SEL |
		BIT_PMU_APB_DPLL0_AGCP_SEL |
		BIT_PMU_APB_DPLL0_WTLCP_SEL |
		BIT_PMU_APB_DPLL0_PUBCP_SEL |
		BIT_PMU_APB_DPLL0_AP_SEL |
		0
	);
	CHIP_REG_OR(REG_PMU_APB_LTEPLL_REL_CFG,
		BIT_PMU_APB_LTEPLL_CM3_SEL |
		BIT_PMU_APB_LTEPLL_AGCP_SEL |
		BIT_PMU_APB_LTEPLL_WTLCP_SEL |
		BIT_PMU_APB_LTEPLL_PUBCP_SEL |
		BIT_PMU_APB_LTEPLL_AP_SEL |
		0
	);
	CHIP_REG_OR(REG_PMU_APB_TWPLL_REL_CFG,
		BIT_PMU_APB_TWPLL_CM3_SEL |
		BIT_PMU_APB_TWPLL_AGCP_SEL |
		BIT_PMU_APB_TWPLL_WTLCP_SEL |
		BIT_PMU_APB_TWPLL_PUBCP_SEL |
		BIT_PMU_APB_TWPLL_AP_SEL |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_LVDSDIS_PLL_REL_CFG,
		BIT_PMU_APB_LVDSDIS_PLL_CM3_SEL |
		BIT_PMU_APB_LVDSDIS_PLL_AGCP_SEL |
		BIT_PMU_APB_LVDSDIS_PLL_WTLCP_SEL |
		BIT_PMU_APB_LVDSDIS_PLL_PUBCP_SEL |
		BIT_PMU_APB_LVDSDIS_PLL_AP_SEL |
		0
	);
}
#endif

void DCDC_ldo_power_on()
{
	ANA_REG_AND(ANA_REG_GLB_DCDC_GPU_PD_HW, ~BIT_DCDC_GPU_PD_HW);
	ANA_REG_AND(ANA_REG_GLB_DCDC_WPA_REG2, ~BIT_DCDC_WPA_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMA0_REG0, ~BIT_LDO_CAMA0_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMA1_REG0, ~BIT_LDO_CAMA1_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMMOT_REG0, ~BIT_LDO_CAMMOT_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_SIM0_PD_REG, ~BIT_LDO_SIM0_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_SIM1_PD_REG, ~BIT_LDO_SIM1_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_VLDO_PD_REG, ~BIT_LDO_VLDO_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_EMMCCORE_REG0, ~BIT_LDO_EMMCCORE_PD); //in fact,it's not needed,the ldo is default on
	ANA_REG_OR(ANA_REG_GLB_LDO_SD_PD_REG, BIT_LDO_SDCORE_PD);
	ANA_REG_OR(ANA_REG_GLB_LDO_SDIO_PD_REG, BIT_LDO_SDIO_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_WIFIPA_REG0, ~BIT_LDO_WIFIPA_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_DCXO_REG0, ~BIT_LDO_DCXO_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_USB33_REG0, ~BIT_LDO_USB33_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMD0_REG0, ~BIT_LDO_CAMD0_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMD1_REG0, ~BIT_LDO_CAMD1_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_CON_REG0, ~BIT_LDO_CON_PD);
	//ANA_REG_AND(ANA_REG_GLB_LDO_CAMIO_REG0, ~BIT_LDO_CAMIO_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_VDDRF_REG0, ~BIT_LDO_RF_PD);
	ANA_REG_AND(ANA_REG_GLB_LDO_SRAM_PD_REG, ~BIT_LDO_SRAM_PD);
	ANA_REG_AND(ANA_REG_GLB_CHGR_DET_FGU_CTRL, ~BIT_LDO_FGU_PD);
}

void pmic_lowpower_config(uint32_t gen_para)
{
#if defined(CONFIG_ADIE_SC2731)
	uint32_t reg_val;
	ANA_REG_SET(ANA_REG_GLB_PWR_WR_PROT_VALUE,0x6e7f);
	while( (ANA_REG_GET(ANA_REG_GLB_PWR_WR_PROT_VALUE) & 0x8000) != 0x8000 );

	ANA_REG_SET(ANA_REG_GLB_POWER_PD_SW,
		//BIT_LDO_DCXO_PD |
		//BIT_LDO_SRAM_PD_SW |
		//BIT_DCDC_RF_PD |
		//BIT_LDO_EMM_PD |
		BIT_DCDC_TOPCLK6M_PD |
		//BIT_DCDC_GEN_PD |
		//BIT_DCDC_MEM_PD |
		//BIT_DCDC_CORE_PD |
		//BIT_DCDC_GPU_PD_SW |
		//BIT_DCDC_ARM0_PD |
		//BIT_DCDC_ARM1_PD |
		//BIT_LDO_AVDD18_PD |
		//BIT_LDO_VDD28_PD |
		//BIT_BG_PD |
		0
	);
	ANA_REG_SET(ANA_REG_GLB_PWR_WR_PROT_VALUE,0x0000);

	ANA_REG_SET(ANA_REG_GLB_SLP_CTRL,
		BIT_LDO_XTL_EN |
		BIT_SLP_BG_LP_EN |
		BIT_SLP_IO_EN |
		BIT_SLP_LDO_PD_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_PD_CTRL,
		//BIT_SLP_DCDCGPU_PD_EN |  /*wa for overshot, is set in ddr shutdown code,and clear after wakup*/
		//BIT_SLP_DCDCGPU_DROP_EN |
		BIT_SLP_DCDCCORE_DROP_EN |
		//BIT_SLP_DCDCRF_PD_EN |   /*control by wcn*;
		//BIT_SLP_DCDCWPA_PD_EN |
		//BIT_SLP_DCDCARM0_PD_EN |  /*control by sleep drv*/
		//BIT_SLP_DCDCARM1_PD_EN |  /*control by sleep drv*/
		//BIT_SLP_DCDCMEM_PD_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL0,
		BIT_SLP_LDORF0_PD_EN |	/*?*/
		//BIT_SLP_LDOEMMCCORE_PD_EN |	/*control by emmc drv*/
		BIT_SLP_LDODCXO_PD_EN |	/*use by the dcxo 32k*/
		//BIT_SLP_LDOWIFIPA_PD_EN |	/*control by wifi drv*/
		//BIT_SLP_LDOVDD28_PD_EN |	/*use by IO no pd*/
		//BIT_SLP_LDOSDCORE_PD_EN |	/*control by sd drv*/
		//BIT_SLP_LDOSDIO_PD_EN |	/*control by sd drv*/
		//BIT_SLP_LDOUSB33_PD_EN |	/*control by usb phy*/
		//BIT_SLP_LDOCAMMOT_PD_EN |	/*control by the drv*/
		//BIT_SLP_LDOCAMIO_PD_EN |	/*control by the drv*/
		//BIT_SLP_LDOCAMD0_PD_EN |	/*control by the drv*/
		//BIT_SLP_LDOCAMD1_PD_EN |	/*control by the drv*/
		//BIT_SLP_LDOCAMA0_PD_EN |	/*control by the drv*/
		//BIT_SLP_LDOCAMA1_PD_EN |	/*control by the drv*/
		BIT_SLP_VLDO_PD_EN |		/*control by the drv*/
		//BIT_SLP_LDOSIM1_PD_EN |	/*control by the drv*/
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL1,
		BIT_SLP_LDOCON_PD_EN |	    /*control by marlin*/
		//BIT_SLP_LDOSIM0_PD_EN |	/*control by the drv*/
		BIT_SLP_LDOAVDD18_PD_EN | 	/*use by the pll/mipi/lvds/usb phy*/
		BIT_SLP_LDOSRAM_PD_EN |	    /*use by L2Cache*/
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_LP_CTRL,
		//BIT_SLP_DCDCRF_LP_EN |   /*control by wcn, not slp_lp*/
		BIT_SLP_DCDCCORE_LP_EN |
		//BIT_SLP_DCDCGPU_LP_EN |
		BIT_SLP_DCDCMEM_LP_EN |
		//BIT_SLP_DCDCARM1_LP_EN |
		//BIT_SLP_DCDCARM0_LP_EN |
		BIT_SLP_DCDCGEN_LP_EN |
		//BIT_SLP_DCDCWPA_LP_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_LP_CTRL0,
		//BIT_SLP_LDORF0_LP_EN |
		//BIT_SLP_LDOEMMCCORE_LP_EN |	/*control by emmc drv*/
		//BIT_SLP_LDODCXO_LP_EN |
		//BIT_SLP_LDOWIFIPA_LP_EN |
		BIT_SLP_LDOVDD28_LP_EN |
		//BIT_SLP_LDOSDCORE_LP_EN |
		//BIT_SLP_LDOSDIO_LP_EN |
		//BIT_SLP_LDOUSB33_LP_EN |
		//BIT_SLP_LDOCAMMOT_LP_EN |
		//BIT_SLP_LDOCAMIO_LP_EN |
		//BIT_SLP_LDOCAMD0_LP_EN |
		//BIT_SLP_LDOCAMD1_LP_EN |
		//BIT_SLP_LDOCAMA0_LP_EN |
		//BIT_SLP_LDOCAMA1_LP_EN |
		//BIT_SLP_VLDO_LP_EN |
		//BIT_SLP_LDOSIM1_LP_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_LP_CTRL1,
		//BIT_SLP_LDOCON_LP_EN |
		//BIT_SLP_LDOSIM0_LP_EN |
		//BIT_SLP_LDOAVDD18_LP_EN |
		//BIT_SLP_LDOSRAM_LP_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN0,
		//BIT_DCDC_CORE_EXT_XTL0_EN |
		BIT_DCDC_CORE_EXT_XTL1_EN |
		BIT_DCDC_CORE_EXT_XTL2_EN |
		//BIT_DCDC_CORE_EXT_XTL3_EN |
		//BIT_DCDC_GPU_EXT_XTL0_EN |
		//BIT_DCDC_GPU_EXT_XTL1_EN |
		//BIT_DCDC_GPU_EXT_XTL2_EN |
		//BIT_DCDC_GPU_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN1,
		//BIT_DCDC_ARM0_EXT_XTL0_EN |
		//BIT_DCDC_ARM0_EXT_XTL1_EN |
		//BIT_DCDC_ARM0_EXT_XTL2_EN |
		//BIT_DCDC_ARM0_EXT_XTL3_EN |
		//BIT_DCDC_ARM1_EXT_XTL0_EN |
		//BIT_DCDC_ARM1_EXT_XTL1_EN |
		//BIT_DCDC_ARM1_EXT_XTL2_EN |
		//BIT_DCDC_ARM1_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN2,
		//BIT_DCDC_MEM_EXT_XTL0_EN |
		BIT_DCDC_MEM_EXT_XTL1_EN |
		BIT_DCDC_MEM_EXT_XTL2_EN |
		//BIT_DCDC_MEM_EXT_XTL3_EN |
		//BIT_DCDC_GEN_EXT_XTL0_EN |
		BIT_DCDC_GEN_EXT_XTL1_EN |
		BIT_DCDC_GEN_EXT_XTL2_EN |
		//BIT_DCDC_GEN_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN3,
		//BIT_DCDC_RF_EXT_XTL0_EN |
		BIT_DCDC_RF_EXT_XTL1_EN |
		BIT_DCDC_RF_EXT_XTL2_EN |
		//BIT_DCDC_RF_EXT_XTL3_EN |
		//BIT_DCDC_WPA_EXT_XTL0_EN |
		//BIT_DCDC_WPA_EXT_XTL1_EN |
		//BIT_DCDC_WPA_EXT_XTL2_EN |
		//BIT_DCDC_WPA_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN0,
		//BIT_LDO_DCXO_EXT_XTL0_EN |
		BIT_LDO_DCXO_EXT_XTL1_EN |
		BIT_LDO_DCXO_EXT_XTL2_EN |
		//BIT_LDO_DCXO_EXT_XTL3_EN |
		//BIT_LDO_VDD28_EXT_XTL0_EN |
		BIT_LDO_VDD28_EXT_XTL1_EN |
		BIT_LDO_VDD28_EXT_XTL2_EN |
		//BIT_LDO_VDD28_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN1,
		//BIT_LDO_RF0_EXT_XTL0_EN |
		BIT_LDO_RF0_EXT_XTL1_EN |
		BIT_LDO_RF0_EXT_XTL2_EN |
		//BIT_LDO_RF0_EXT_XTL3_EN |
		//BIT_LDO_WIFIPA_EXT_XTL0_EN |
		//BIT_LDO_WIFIPA_EXT_XTL1_EN |
		BIT_LDO_WIFIPA_EXT_XTL2_EN |
		//BIT_LDO_WIFIPA_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN2,
		//BIT_LDO_SIM0_EXT_XTL0_EN |
		//BIT_LDO_SIM0_EXT_XTL1_EN |
		//BIT_LDO_SIM0_EXT_XTL2_EN |
		//BIT_LDO_SIM0_EXT_XTL3_EN |
		//BIT_LDO_SIM1_EXT_XTL0_EN |
		//BIT_LDO_SIM1_EXT_XTL1_EN |
		//BIT_LDO_SIM1_EXT_XTL2_EN |
		//BIT_LDO_SIM1_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN3,
		//BIT_LDO_VLDO_EXT_XTL0_EN |
		//BIT_LDO_VLDO_EXT_XTL1_EN |
		//BIT_LDO_VLDO_EXT_XTL2_EN |
		//BIT_LDO_VLDO_EXT_XTL3_EN |
		//BIT_LDO_SRAM_EXT_XTL0_EN |
		//BIT_LDO_SRAM_EXT_XTL1_EN |
		//BIT_LDO_SRAM_EXT_XTL2_EN |
		//BIT_LDO_SRAM_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN4,
		//BIT_LDO_CAMMOT_EXT_XTL0_EN |
		//BIT_LDO_CAMMOT_EXT_XTL1_EN |
		//BIT_LDO_CAMMOT_EXT_XTL2_EN |
		//BIT_LDO_CAMMOT_EXT_XTL3_EN |
		//BIT_LDO_CAMIO_EXT_XTL0_EN |
		//BIT_LDO_CAMIO_EXT_XTL1_EN |
		//BIT_LDO_CAMIO_EXT_XTL2_EN |
		//BIT_LDO_CAMIO_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN5,
		//BIT_LDO_CAMA0_EXT_XTL0_EN |
		//BIT_LDO_CAMA0_EXT_XTL1_EN |
		//BIT_LDO_CAMA0_EXT_XTL2_EN |
		//BIT_LDO_CAMA0_EXT_XTL3_EN |
		//BIT_LDO_CAMA1_EXT_XTL0_EN |
		//BIT_LDO_CAMA1_EXT_XTL1_EN |
		//BIT_LDO_CAMA1_EXT_XTL2_EN |
		//BIT_LDO_CAMA1_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN6,
		//BIT_LDO_CAMD0_EXT_XTL0_EN |
		//BIT_LDO_CAMD0_EXT_XTL1_EN |
		//BIT_LDO_CAMD0_EXT_XTL2_EN |
		//BIT_LDO_CAMD0_EXT_XTL3_EN |
		//BIT_LDO_CAMD1_EXT_XTL0_EN |
		//BIT_LDO_CAMD1_EXT_XTL1_EN |
		//BIT_LDO_CAMD1_EXT_XTL2_EN |
		//BIT_LDO_CAMD1_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN7,
		//BIT_LDO_SDIO_EXT_XTL0_EN |
		//BIT_LDO_SDIO_EXT_XTL1_EN |
		//BIT_LDO_SDIO_EXT_XTL2_EN |
		//BIT_LDO_SDIO_EXT_XTL3_EN |
		//BIT_LDO_SDCORE_EXT_XTL0_EN |
		//BIT_LDO_SDCORE_EXT_XTL1_EN |
		//BIT_LDO_SDCORE_EXT_XTL2_EN |
		//BIT_LDO_SDCORE_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN8,
		//BIT_LDO_EMMCCORE_EXT_XTL0_EN |
		//BIT_LDO_EMMCCORE_EXT_XTL1_EN |
		//BIT_LDO_EMMCCORE_EXT_XTL2_EN |
		//BIT_LDO_EMMCCORE_EXT_XTL3_EN |
		//BIT_LDO_USB33_EXT_XTL0_EN |
		//BIT_LDO_USB33_EXT_XTL1_EN |
		//BIT_LDO_USB33_EXT_XTL2_EN |
		//BIT_LDO_USB33_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN9,
		//BIT_LDO_KPLED_EXT_XTL0_EN |
		//BIT_LDO_KPLED_EXT_XTL1_EN |
		//BIT_LDO_KPLED_EXT_XTL2_EN |
		//BIT_LDO_KPLED_EXT_XTL3_EN |
		//BIT_LDO_VIBR_EXT_XTL0_EN |
		//BIT_LDO_VIBR_EXT_XTL1_EN |
		//BIT_LDO_VIBR_EXT_XTL2_EN |
		//BIT_LDO_VIBR_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN10,
		//BIT_LDO_CON_EXT_XTL0_EN |
		BIT_LDO_CON_EXT_XTL1_EN |
		BIT_LDO_CON_EXT_XTL2_EN |
		//BIT_LDO_CON_EXT_XTL3_EN |
		//BIT_LDO_AVDD18_EXT_XTL0_EN |
		BIT_LDO_AVDD18_EXT_XTL1_EN |
		BIT_LDO_AVDD18_EXT_XTL2_EN |
		//BIT_LDO_AVDD18_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_XO_BG_XTL_EN,
		//BIT_XO_EXT_XTL0_EN |
		BIT_XO_EXT_XTL1_EN |
		BIT_XO_EXT_XTL2_EN |
		//BIT_XO_EXT_XTL3_EN |
		//BIT_BG_EXT_XTL0_EN |
		BIT_BG_EXT_XTL1_EN |
		BIT_BG_EXT_XTL2_EN |
		//BIT_BG_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_XTL_WAIT_CTRL,
		BIT_CUR_SEL |
		BIT_EXT_XTL3_FOR_26M_EN |
		BIT_EXT_XTL2_FOR_26M_EN |
		BIT_EXT_XTL1_FOR_26M_EN |
		BIT_EXT_XTL0_FOR_26M_EN |
		BIT_SLP_XTLBUF_PD_EN |
		BIT_XTL_EN |
		BITS_XTL_WAIT(0x39) |  /*how long need to wait*/
		0
	);

	/*when bring up we power on all dcdc & ldo*/
	DCDC_ldo_power_on();

#endif
}

void sprd_pmu_lowpower_init(void)
{
	uint32_t reg_val;
#if defined(CONFIG_FPGA)
	return;
#endif
	pmic_lowpower_config(0x00000000);
	//xtl_xtlbuf_sel_config(0x00000000);
	//pll_sel_config(0x00000000);
	CSP_Init(0x50001800);
}

#ifdef CONFIG_DL_POWER_CONTROL
#define VDDGPU_EN_GPIO   163
void dl_power_control(void)
{
	pmu_cfg_for_dl_power();

	ANA_REG_OR(ANA_REG_GLB_DCDC_WPA_REG2, BIT_DCDC_WPA_PD);  //shutdown VDDWPA
	ANA_REG_OR(ANA_REG_GLB_LDO_VLDO_PD_REG, BIT_LDO_VLDO_PD); //shutdown VDDSIM2

	sprd_gpio_request(NULL, VDDGPU_EN_GPIO);                 //shutdown VDDGPU
	sprd_gpio_direction_output(NULL, VDDGPU_EN_GPIO, 0);
}
#endif