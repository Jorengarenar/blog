// http://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/drivers/clk/mmp/clk-audio.c#n345

// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * MMP Audio Clock Controller driver
 *
 * Copyright (C) 2020 Lubomir Rintel <lkundrak@v3.sk>
 */

static int mmp2_audio_clk_probe(struct platform_device *pdev)
{
	struct mmp2_audio_clk *priv;
	int ret;

	priv = devm_kzalloc(&pdev->dev,
			    struct_size(priv, clk_data.hws,
					MMP2_CLK_AUDIO_NR_CLKS),
			    GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	spin_lock_init(&priv->lock);
	platform_set_drvdata(pdev, priv);

	priv->mmio_base = devm_platform_ioremap_resource(pdev, 0);
	if (IS_ERR(priv->mmio_base))
		return PTR_ERR(priv->mmio_base);

	pm_runtime_enable(&pdev->dev);
	ret = pm_clk_create(&pdev->dev);
	if (ret)
		goto disable_pm_runtime;

	ret = pm_clk_add(&pdev->dev, "audio");
	if (ret)
		goto destroy_pm_clk;

	ret = register_clocks(priv, &pdev->dev);
	if (ret)
		goto destroy_pm_clk;

	return 0;

destroy_pm_clk:
	pm_clk_destroy(&pdev->dev);
disable_pm_runtime:
	pm_runtime_disable(&pdev->dev);

	return ret;
}

// vim: ts=8 noet
