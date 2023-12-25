static int mmp2_audio_clk_probe(struct platform_device *pdev)
{
    // ...
    pm_runtime_enable(&pdev->dev);

    bool destroy_pm_clk = false;

    ret = pm_clk_create(&pdev->dev);
    if (!ret) {
        ret = pm_clk_add(&pdev->dev, "audio");
        if (ret) {
            destroy_pm_clk = true;
        }
    }
    if (!ret) {
        ret = register_clocks(priv, &pdev->dev);
        if (ret) {
            destroy_pm_clk = true;
        }
    }

    if (ret) {
        if (destroy_pm_clk) {
            pm_clk_destroy(&pdev->dev);
        }
        pm_runtime_disable(&pdev->dev);
        return ret;
    }

    return 0;
}
