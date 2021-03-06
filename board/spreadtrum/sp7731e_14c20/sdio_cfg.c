/*
 * This file is produced by tools!!
 *
 * Copyright (C) 2016 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <asm/arch/sprd_reg.h>
#include <asm/io.h>
#include <asm/arch/sdio_cfg.h>
#include <asm/arch/sdio_reg.h>
#include <asm/arch/common.h>

/*
 * TODO：
 * Now many macros(such as: SPRD_EMMC_BASE, REG_AP_CLK_EMMC_CFG)
 * have not defined in spreadtrum platform, so we use a immediate
 * value instead of it.
 * These immediate values should be removed if the corresponding
 * macros are defined.
 */
const struct sdio_base_info sdio_ctrl_info[2] = {
{
	EMMC,
	/* SPRD_EMMC_BASE, */
	0X20600000,
#ifdef CONFIG_FPGA
             NULL,
             NULL,
	      36000000,
	      100000,
#else
	REG_AON_CLK_EMMC_2X_CFG,
	BIT_0|BIT_1,
	192000000,
	400000,
#endif
	REG_AP_AHB_AHB_EB,
	BIT_AP_AHB_EMMC_EB,
	REG_AP_AHB_AHB_RST,
	BIT_AP_AHB_EMMC_SOFT_RST,
	REG_AON_APB_CLK_EB0,
	BIT_0|BIT_1,

		"vddgen",
		"vddemmccore",
	},
	{
		SD,
		0X20300000,
#ifdef CONFIG_FPGA
             NULL,
             NULL,
	      36000000,
	      100000,
#else
	REG_AON_CLK_SDIO0_2X_CFG,
	BIT_0|BIT_1,
	192000000,
	400000,
#endif

	REG_AP_AHB_AHB_EB,
	BIT_AP_AHB_SDIO0_EB,
	REG_AP_AHB_AHB_RST,
	BIT_AP_AHB_SDIO0_SOFT_RST,
	REG_AON_APB_CLK_EB0,
	BIT_2|BIT_3,

		"vddsdio",
		"vddsdcore",
	}
};

struct sdio_base_info *get_sdcontrol_info(uint32_t device_type)
{
	return  &sdio_ctrl_info[device_type];
}

