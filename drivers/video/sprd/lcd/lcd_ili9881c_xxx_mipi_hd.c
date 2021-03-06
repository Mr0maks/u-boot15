/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
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

#include "sprd_panel.h"
#include "sprd_dsi.h"
#include "dsi/mipi_dsi_api.h"
#include "sprd_dphy.h"

static uint8_t init_data[] = {
	0x39, 0x00, 0x00, 0x04, 0xFF, 0x98, 0x81, 0x03,
	0x23, 0x00, 0x00, 0x02, 0x01, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x02, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x03, 0x73,
	0x23, 0x00, 0x00, 0x02, 0x04, 0x73,
	0x23, 0x00, 0x00, 0x02, 0x05, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x06, 0x06,
	0x23, 0x00, 0x00, 0x02, 0x07, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x08, 0x05,
	0x23, 0x00, 0x00, 0x02, 0x09, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x0a, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x0b, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0c, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x0d, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x0e, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x0f, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x10, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x11, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x12, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x13, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x14, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x15, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x16, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x17, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x18, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x19, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1a, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1b, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1c, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1d, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x1e, 0xC8,
	0x23, 0x00, 0x00, 0x02, 0x1f, 0x80,
	0x23, 0x00, 0x00, 0x02, 0x20, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x21, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x22, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x23, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x24, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x25, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x26, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x27, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x28, 0xfb,
	0x23, 0x00, 0x00, 0x02, 0x29, 0x43,
	0x23, 0x00, 0x00, 0x02, 0x2a, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x2b, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x2c, 0x07,
	0x23, 0x00, 0x00, 0x02, 0x2d, 0x07,
	0x23, 0x00, 0x00, 0x02, 0x2e, 0xff,
	0x23, 0x00, 0x00, 0x02, 0x2f, 0xff,
	0x23, 0x00, 0x00, 0x02, 0x30, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x31, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x32, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x33, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x34, 0x84,
	0x23, 0x00, 0x00, 0x02, 0x35, 0x80,
	0x23, 0x00, 0x00, 0x02, 0x36, 0x07,
	0x23, 0x00, 0x00, 0x02, 0x37, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x38, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x39, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3a, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3b, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3c, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3d, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3e, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x3f, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x40, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x41, 0x88,
	0x23, 0x00, 0x00, 0x02, 0x42, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x43, 0x80,
	0x23, 0x00, 0x00, 0x02, 0x44, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x50, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x51, 0x23,
	0x23, 0x00, 0x00, 0x02, 0x52, 0x45,
	0x23, 0x00, 0x00, 0x02, 0x53, 0x67,
	0x23, 0x00, 0x00, 0x02, 0x54, 0x89,
	0x23, 0x00, 0x00, 0x02, 0x55, 0xab,
	0x23, 0x00, 0x00, 0x02, 0x56, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x57, 0x23,
	0x23, 0x00, 0x00, 0x02, 0x58, 0x45,
	0x23, 0x00, 0x00, 0x02, 0x59, 0x67,
	0x23, 0x00, 0x00, 0x02, 0x5a, 0x89,
	0x23, 0x00, 0x00, 0x02, 0x5b, 0xab,
	0x23, 0x00, 0x00, 0x02, 0x5c, 0xcd,
	0x23, 0x00, 0x00, 0x02, 0x5d, 0xef,
	0x23, 0x00, 0x00, 0x02, 0x5e, 0x10,
	0x23, 0x00, 0x00, 0x02, 0x5f, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x60, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x61, 0x09,
	0x23, 0x00, 0x00, 0x02, 0x62, 0x10,
	0x23, 0x00, 0x00, 0x02, 0x63, 0x12,
	0x23, 0x00, 0x00, 0x02, 0x64, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x65, 0x13,
	0x23, 0x00, 0x00, 0x02, 0x66, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x67, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x68, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x69, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x6a, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x6b, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x6c, 0x0e,
	0x23, 0x00, 0x00, 0x02, 0x6d, 0x0d,
	0x23, 0x00, 0x00, 0x02, 0x6e, 0x0f,
	0x23, 0x00, 0x00, 0x02, 0x6f, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x70, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x71, 0x06,
	0x23, 0x00, 0x00, 0x02, 0x72, 0x07,
	0x23, 0x00, 0x00, 0x02, 0x73, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x74, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x75, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x76, 0x07,
	0x23, 0x00, 0x00, 0x02, 0x77, 0x06,
	0x23, 0x00, 0x00, 0x02, 0x78, 0x11,
	0x23, 0x00, 0x00, 0x02, 0x79, 0x13,
	0x23, 0x00, 0x00, 0x02, 0x7a, 0x10,
	0x23, 0x00, 0x00, 0x02, 0x7b, 0x12,
	0x23, 0x00, 0x00, 0x02, 0x7c, 0x0f,
	0x23, 0x00, 0x00, 0x02, 0x7d, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x7e, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x7f, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x80, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x81, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x82, 0x0d,
	0x23, 0x00, 0x00, 0x02, 0x83, 0x0e,
	0x23, 0x00, 0x00, 0x02, 0x84, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0x85, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x86, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x87, 0x09,
	0x23, 0x00, 0x00, 0x02, 0x88, 0x08,
	0x23, 0x00, 0x00, 0x02, 0x89, 0x02,
	0x23, 0x00, 0x00, 0x02, 0x8A, 0x02,
	0x39, 0x00, 0x00, 0x04, 0xFF, 0x98, 0x81, 0x04,
	0x23, 0x00, 0x00, 0x02, 0x6C, 0x15,
	0x23, 0x00, 0x00, 0x02, 0x6E, 0x2d,
	0x23, 0x00, 0x00, 0x02, 0x6F, 0x35,
	0x23, 0x00, 0x00, 0x02, 0x3A, 0xA4,
	0x23, 0x00, 0x00, 0x02, 0x8D, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x87, 0xBA,
	0x23, 0x00, 0x00, 0x02, 0x26, 0x76,
	0x23, 0x00, 0x00, 0x02, 0xB2, 0xD1,
	0x23, 0x00, 0x00, 0x02, 0xB5, 0x06,
	0x39, 0x00, 0x00, 0x04, 0xFF, 0x98, 0x81, 0x01,
	0x23, 0x00, 0x00, 0x02, 0x22, 0x3A,
	0x23, 0x00, 0x00, 0x02, 0x31, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x53, 0x56,
	0x23, 0x00, 0x00, 0x02, 0x55, 0xc0,
	0x23, 0x00, 0x00, 0x02, 0x50, 0xb7,
	0x23, 0x00, 0x00, 0x02, 0x51, 0xb7,
	0x23, 0x00, 0x00, 0x02, 0x60, 0x14,
	0x23, 0x00, 0x00, 0x02, 0x61, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x62, 0x19,
	0x23, 0x00, 0x00, 0x02, 0x63, 0x10,
	0x23, 0x00, 0x00, 0x02, 0xA0, 0x00,
	0x23, 0x00, 0x00, 0x02, 0xA1, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xA2, 0x2b,
	0x23, 0x00, 0x00, 0x02, 0xA3, 0x13,
	0x23, 0x00, 0x00, 0x02, 0xA4, 0x15,
	0x23, 0x00, 0x00, 0x02, 0xA5, 0x29,
	0x23, 0x00, 0x00, 0x02, 0xA6, 0x1d,
	0x23, 0x00, 0x00, 0x02, 0xA7, 0x1e,
	0x23, 0x00, 0x00, 0x02, 0xA8, 0x9a,
	0x23, 0x00, 0x00, 0x02, 0xA9, 0x1d,
	0x23, 0x00, 0x00, 0x02, 0xAA, 0x29,
	0x23, 0x00, 0x00, 0x02, 0xAB, 0x8d,
	0x23, 0x00, 0x00, 0x02, 0xAC, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xAD, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xAE, 0x50,
	0x23, 0x00, 0x00, 0x02, 0xAF, 0x25,
	0x23, 0x00, 0x00, 0x02, 0xB0, 0x2a,
	0x23, 0x00, 0x00, 0x02, 0xB1, 0x57,
	0x23, 0x00, 0x00, 0x02, 0xB2, 0x60,
	0x23, 0x00, 0x00, 0x02, 0xB3, 0x28,
	0x23, 0x00, 0x00, 0x02, 0xC0, 0x0c,
	0x23, 0x00, 0x00, 0x02, 0xC1, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xC2, 0x2b,
	0x23, 0x00, 0x00, 0x02, 0xC3, 0x13,
	0x23, 0x00, 0x00, 0x02, 0xC4, 0x15,
	0x23, 0x00, 0x00, 0x02, 0xC5, 0x29,
	0x23, 0x00, 0x00, 0x02, 0xC6, 0x1d,
	0x23, 0x00, 0x00, 0x02, 0xC7, 0x1e,
	0x23, 0x00, 0x00, 0x02, 0xC8, 0x9a,
	0x23, 0x00, 0x00, 0x02, 0xC9, 0x1d,
	0x23, 0x00, 0x00, 0x02, 0xCA, 0x29,
	0x23, 0x00, 0x00, 0x02, 0xCB, 0x8d,
	0x23, 0x00, 0x00, 0x02, 0xCC, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xCD, 0x1c,
	0x23, 0x00, 0x00, 0x02, 0xCE, 0x50,
	0x23, 0x00, 0x00, 0x02, 0xCF, 0x25,
	0x23, 0x00, 0x00, 0x02, 0xD0, 0x2a,
	0x23, 0x00, 0x00, 0x02, 0xD1, 0x57,
	0x23, 0x00, 0x00, 0x02, 0xD2, 0x63,
	0x23, 0x00, 0x00, 0x02, 0xD3, 0x28,
	0x39, 0x00, 0x00, 0x04, 0xFF, 0x98, 0x81, 0x00,
	0x23, 0x00, 0x00, 0x02, 0x35, 0x00,
	0x23, 0x78, 0x00, 0x02, 0x11, 0x00,
	0x23, 0x0A, 0x00, 0x02, 0x29, 0x00,
	CMD_END
};

static int mipi_dsi_send_cmds(struct sprd_dsi *dsi, void *data)
{
	uint16_t len;
	struct dsi_cmd_desc *cmds = data;

	if ((cmds == NULL) || (dsi == NULL))
		return -1;

	for (; cmds->data_type != CMD_END;) {
		len = (cmds->wc_h << 8) | cmds->wc_l;
		mipi_dsi_gen_write(dsi, cmds->payload, len);
		if (cmds->wait)
			msleep(cmds->wait);
		cmds = (struct dsi_cmd_desc *)(cmds->payload + len);
	}
	return 0;
}

static int ili9881c_init(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct sprd_dphy *dphy = &dphy_device;

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_send_cmds(dsi, init_data);
	mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);
	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	return 0;
}

static int ili9881c_readid(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	uint8_t cmd[] = {0xFF, 0x98, 0x81, 0x01};
	uint8_t read_buf[4] = {0};

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_gen_write(dsi, cmd, ARRAY_SIZE(cmd));
	mipi_dsi_set_max_return_size(dsi, 1);
	mipi_dsi_dcs_read(dsi, 0x00, &read_buf[0], 1);
	mipi_dsi_dcs_read(dsi, 0x01, &read_buf[1], 1);

	if ((read_buf[0] == 0x98) && (read_buf[1] == 0x81)) {
		pr_info("ili9881c read id success!\n");
		return 0;
	}

	pr_err("ili9881c read id failed!\n");
	return -1;
}

static int ili9881c_power(int on)
{
	if (on) {
		sprd_gpio_request(NULL, CONFIG_LCM_GPIO_RSTN);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(20);
	} else {
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
	}

	return 0;
}

static struct panel_ops ili9881c_ops = {
	.init = ili9881c_init,
	.read_id = ili9881c_readid,
	.power = ili9881c_power,
};

static struct panel_info ili9881c_info = {
	/* common parameters */
	.lcd_name = "lcd_ili9881c_xxx_mipi_fhd",
	.type = SPRD_PANEL_TYPE_MIPI,
	.bpp = 24,
//	.fps = 3,
	.width = 720,
	.height = 1280,

	/* DPI specific parameters */
	.pixel_clk = 64000000,
	.rgb_timing = {
		.hfp = 52,
		.hbp = 26,
		.hsync = 25,
		.vfp = 5,
		.vbp = 9,
		.vsync = 2,
	},

	/* MIPI DSI specific parameters */
	.phy_freq = 500000,
	.lane_num = 4,
	.work_mode = SPRD_MIPI_MODE_VIDEO,
	.burst_mode = PANEL_VIDEO_BURST_MODE,
	.nc_clk_en = false,
};

struct panel_driver ili9881c_xxx_driver = {
	.info = &ili9881c_info,
	.ops = &ili9881c_ops,
};
