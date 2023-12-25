static int mmp2_audio_clk_probe(struct platform_device *pdev)
{
    // ...
    pm_runtime_enable(&pdev->dev);

    ret = pm_clk_create(&pdev->dev);
    if (ret) {
        pm_runtime_disable(&pdev->dev);
        return ret;
    }

    ret = pm_clk_add(&pdev->dev, "audio");
    if (ret) {
        pm_clk_destroy(&pdev->dev);
        pm_runtime_disable(&pdev->dev);
        return ret;
    }

    ret = register_clocks(priv, &pdev->dev);
    if (ret) {
        pm_clk_destroy(&pdev->dev);
        pm_runtime_disable(&pdev->dev);
        return ret;
    }

    return 0;
}
