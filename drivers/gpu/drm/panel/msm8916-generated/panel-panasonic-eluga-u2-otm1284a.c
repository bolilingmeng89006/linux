// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct otm1284a {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data otm1284a_supplies[] = {
	{ .supply = "vdd" },
	{ .supply = "vddio" },
};

static inline struct otm1284a *to_otm1284a(struct drm_panel *panel)
{
	return container_of_const(panel, struct otm1284a, panel);
}

static void otm1284a_reset(struct otm1284a *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int otm1284a_on(struct otm1284a *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x12, 0x84, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x12, 0x84);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x92);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x30, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x64, 0x00, 0x0e, 0x12, 0x00,
					 0x64, 0x0e, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x55);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x81);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x87);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x81);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x55);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x82);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x85);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x87);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x18);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4,
					 0x05, 0x10, 0x06, 0x02, 0x05, 0x15,
					 0x10, 0x05, 0x10, 0x07, 0x02, 0x05,
					 0x15, 0x10);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xbb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x91);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x16, 0x52);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0x94, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x84);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5,
					 0x02, 0x11, 0x02, 0x15);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x50);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x94);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x66);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb8);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x94);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x06, 0x15);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0xcc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x05, 0x05,
					 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
					 0x05, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
					 0x05, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
					 0xff, 0xfc, 0xff, 0xff, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x0c, 0x0a, 0x10, 0x0e, 0x02, 0x04,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x06, 0x2e,
					 0x2d, 0x0b, 0x09, 0x0f, 0x0d, 0x01,
					 0x03, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
					 0x2e, 0x2d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x0d, 0x0f, 0x09, 0x0b, 0x03, 0x01,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x06, 0x2d,
					 0x2e, 0x0e, 0x10, 0x0a, 0x0c, 0x04,
					 0x02, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
					 0x2d, 0x2e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x8b, 0x03, 0x18, 0x8a, 0x03, 0x18,
					 0x89, 0x03, 0x18, 0x88, 0x03, 0x18);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x38, 0x0f, 0x18, 0x38, 0x0e, 0x18,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x38, 0x07, 0x05, 0x00, 0x00, 0x18,
					 0x00, 0x38, 0x06, 0x05, 0x01, 0x00,
					 0x18, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x38, 0x05, 0x05, 0x02, 0x00, 0x18,
					 0x00, 0x38, 0x04, 0x05, 0x03, 0x00,
					 0x18, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x38, 0x03, 0x05, 0x04, 0x00, 0x18,
					 0x00, 0x38, 0x02, 0x05, 0x05, 0x00,
					 0x18, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce,
					 0x38, 0x01, 0x05, 0x06, 0x00, 0x18,
					 0x00, 0x38, 0x00, 0x05, 0x07, 0x00,
					 0x18, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf,
					 0x01, 0x01, 0x20, 0x20, 0x00, 0x00,
					 0x02, 0x81, 0x00, 0x03, 0x08);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5,
					 0x38, 0x11, 0x7f, 0x38, 0x11, 0x7f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1,
					 0x05, 0x17, 0x23, 0x32, 0x41, 0x50,
					 0x54, 0x83, 0x75, 0x90, 0x72, 0x5a,
					 0x6d, 0x4a, 0x49, 0x3c, 0x31, 0x26,
					 0x1e, 0x05);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2,
					 0x05, 0x16, 0x23, 0x31, 0x40, 0x50,
					 0x54, 0x83, 0x75, 0x90, 0x72, 0x5a,
					 0x6d, 0x49, 0x49, 0x3c, 0x31, 0x26,
					 0x1d, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x24);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x11, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x29, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 50);

	return dsi_ctx.accum_err;
}

static int otm1284a_off(struct otm1284a *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int otm1284a_prepare(struct drm_panel *panel)
{
	struct otm1284a *ctx = to_otm1284a(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(otm1284a_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	otm1284a_reset(ctx);

	ret = otm1284a_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(otm1284a_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int otm1284a_unprepare(struct drm_panel *panel)
{
	struct otm1284a *ctx = to_otm1284a(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = otm1284a_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(otm1284a_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode otm1284a_mode = {
	.clock = (720 + 64 + 12 + 64) * (1280 + 10 + 5 + 13) * 60 / 1000,
	.hdisplay = 720,
	.hsync_start = 720 + 64,
	.hsync_end = 720 + 64 + 12,
	.htotal = 720 + 64 + 12 + 64,
	.vdisplay = 1280,
	.vsync_start = 1280 + 10,
	.vsync_end = 1280 + 10 + 5,
	.vtotal = 1280 + 10 + 5 + 13,
	.width_mm = 62,
	.height_mm = 110,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int otm1284a_get_modes(struct drm_panel *panel,
			      struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &otm1284a_mode);
}

static const struct drm_panel_funcs otm1284a_panel_funcs = {
	.prepare = otm1284a_prepare,
	.unprepare = otm1284a_unprepare,
	.get_modes = otm1284a_get_modes,
};

static int otm1284a_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int otm1284a_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness & 0xff;
}

static const struct backlight_ops otm1284a_bl_ops = {
	.update_status = otm1284a_bl_update_status,
	.get_brightness = otm1284a_bl_get_brightness,
};

static struct backlight_device *
otm1284a_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 255,
		.max_brightness = 255,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &otm1284a_bl_ops, &props);
}

static int otm1284a_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct otm1284a *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct otm1284a, panel,
				   &otm1284a_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(otm1284a_supplies),
					    otm1284a_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = otm1284a_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void otm1284a_remove(struct mipi_dsi_device *dsi)
{
	struct otm1284a *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id otm1284a_of_match[] = {
	{ .compatible = "panasonic,eluga-u2-otm1284a" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, otm1284a_of_match);

static struct mipi_dsi_driver otm1284a_driver = {
	.probe = otm1284a_probe,
	.remove = otm1284a_remove,
	.driver = {
		.name = "panel-panasonic-eluga-u2-otm1284a",
		.of_match_table = otm1284a_of_match,
	},
};
module_mipi_dsi_driver(otm1284a_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for otm1284a 720p video mode dsi panel");
MODULE_LICENSE("GPL");
