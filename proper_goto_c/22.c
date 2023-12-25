static int mmp2_audio_clk_probe(struct platform_device *pdev)
{
    // ...
    pm_runtime_enable(&pdev->dev);

    do {
        ret = pm_clk_create(&pdev->dev);
        if (ret) break;

        do {
            ret = pm_clk_add(&pdev->dev, "audio");
            if (ret) break;

            ret = register_clocks(priv, &pdev->dev);
            if (ret) break;
        } while (0);
        pm_clk_destroy(&pdev->dev);
    } while (0);
    pm_runtime_disable(&pdev->dev);

    return ret;
}
