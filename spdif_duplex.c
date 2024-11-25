// SPDX-License-Identifier: GPL-2.0-only
/*
 * ALSA SoC SPDIF DUPLEX (Digital Interface Reciever) driver
 *
 * Based on ALSA SoC SPDIF DIT driver
 *
 *  This driver is used by controllers which can operate in DUPLEX (SPDI/F) where
 *  no codec is needed.  This file provides stub codec that can be used
 *  in these configurations.
 *
 * Author:      Brian Walton <brian@riban.co.uk> based on code by Vipin Kumar,  <vipin.kumar@st.com>
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <sound/soc.h>
#include <sound/pcm.h>
#include <sound/initval.h>
#include <linux/of.h>

static const struct snd_soc_dapm_widget duplex_widgets[] = {
	SND_SOC_DAPM_INPUT("spdif-in"),
	SND_SOC_DAPM_INPUT("spdif-out"),
};

static const struct snd_soc_dapm_route duplex_routes[] = {
	{ "Capture", NULL, "spdif-in" },
	{ "Playback", NULL, "spdif-out" },
};

#define STUB_RATES	(SNDRV_PCM_RATE_8000_96000 | \
			 SNDRV_PCM_RATE_48000)
#define STUB_FORMATS	(SNDRV_PCM_FMTBIT_S16_LE | \
			SNDRV_PCM_FMTBIT_S20_3LE | \
			SNDRV_PCM_FMTBIT_S24_LE  | \
			SNDRV_PCM_FMTBIT_S32_LE | \
			SNDRV_PCM_FMTBIT_IEC958_SUBFRAME_LE)

static const struct snd_soc_component_driver soc_codec_spdif_duplex = {
	.dapm_widgets		= duplex_widgets,
	.num_dapm_widgets	= ARRAY_SIZE(duplex_widgets),
	.dapm_routes		= duplex_routes,
	.num_dapm_routes	= ARRAY_SIZE(duplex_routes),
	.idle_bias_on		= 1,
	.use_pmdown_time	= 1,
	.endianness		= 1,
};

static struct snd_soc_dai_driver duplex_stub_dai = {
	.name		= "duplex-hifi",
	.capture	= {
		.stream_name	= "Capture",
		.channels_min	= 1,
		.channels_max	= 384,
		.rates		= STUB_RATES,
		.formats	= STUB_FORMATS,
	},
	.playback	= {
		.stream_name	= "Playback",
		.channels_min	= 1,
		.channels_max	= 384,
		.rates		= STUB_RATES,
		.formats	= STUB_FORMATS,
	},
};

static int spdif_duplex_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
			&soc_codec_spdif_duplex,
			&duplex_stub_dai, 1);
}

static const struct of_device_id spdif_duplex_dt_ids[] = {
	{ .compatible = "linux,spdif-duplex", },
	{ }
};
MODULE_DEVICE_TABLE(of, spdif_duplex_dt_ids);

static struct platform_driver spdif_duplex_driver = {
	.probe		= spdif_duplex_probe,
	.driver		= {
		.name	= "spdif-duplex",
		.of_match_table = of_match_ptr(spdif_duplex_dt_ids),
	},
};

module_platform_driver(spdif_duplex_driver);

MODULE_DESCRIPTION("ASoC SPDIF duplex driver");
MODULE_AUTHOR("Brian Walton <riban@zynthian.org>, Vipin Kumar <vipin.kumar@st.com>");
MODULE_LICENSE("GPL");