static inline int mmp2_audio_clk_probe_3(struct platform_device *pdev)
{
    int ret = register_clocks(priv, &pdev->dev);
    if (ret) {
        pm_clk_destroy(&pdev->dev);
    }
    return ret;
}

static inline int mmp2_audio_clk_probe_2(struct platform_device *pdev)
{
    int ret = pm_clk_add(&pdev->dev, "audio");
    if (ret) {
        pm_clk_destroy(&pdev->dev);
    } else {
        ret = mmp2_audio_clk_probe_3(pdev);
    }
    return ret;
}

static inline int mmp2_audio_clk_probe_1(struct platform_device *pdev)
{
    int ret = pm_clk_create(&pdev->dev);
    if (ret) {
        pm_runtime_disable(&pdev->dev);
    } else {
        ret = mmp2_audio_clk_probe_2(pdev);
        if (ret) {
            pm_runtime_disable(&pdev->dev);
        }
    }
    return ret;
}

static int mmp2_audio_clk_probe(struct platform_device* pdev)
{
    // ... {{{
	struct mmp2_audio_clk *priv;
	int ret;

	priv = devm_kzalloc(&pdev->dev,
			            struct_size(priv, clk_data.hws,
					                MMP2_CLK_AUDIO_NR_CLKS),
			            GFP_KERNEL);
	if (!priv) {
		return -ENOMEM;
    }

	spin_lock_init(&priv->lock);
	platform_set_drvdata(pdev, priv);

	priv->mmio_base = devm_platform_ioremap_resource(pdev, 0);
	if (IS_ERR(priv->mmio_base)) {
		return PTR_ERR(priv->mmio_base);
    }
    // }}}
    pm_runtime_enable(&pdev->dev);

    ret = mmp2_audio_clk_probe_1(pdev);

    return ret;
}

// vim: fen
