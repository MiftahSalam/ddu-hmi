package skm.ddu.mlh.views.components;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import javafx.application.Platform;
import javafx.beans.binding.Bindings;
import javafx.beans.binding.DoubleBinding;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelDataPeriodicModel;
import skm.ddu.mlh.services.ChannelConfigService;
import skm.ddu.mlh.shared.constants.ChannelConstant;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonState;

public class ChannelRow extends HBox {
    private final int rowNumber;
    private final ChannelConstant.CH_IO_FUNCTION ioFunction;
    private final List<ChannelButton> buttons = new ArrayList<>();
    private ChannelConfigService channelConfigService = ChannelConfigService.getInstance();
    private static ScheduledExecutorService scheduledExecutorService;

    static {
        scheduledExecutorService = new ScheduledThreadPoolExecutor(10);
    }

    public ChannelRow(int row) {
        rowNumber = row;
        ioFunction = ChannelConstant.CH_IO_MAP.get(row);

        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        ChannelButton chNum = new ChannelButton(rowNumber, ChannelButtonRole.CH_NUMBER);
        chNum.setText(String.format("%d\n(%s)", row + 1, ioFunction.toString()));
        setHgrow(chNum, Priority.ALWAYS);

        ChannelButton chName = new ChannelButton(rowNumber, ChannelButtonRole.CH_NAME);
        ChannelConfigInfoModel channelConfigInfo = channelConfigService.getChannelConfigInfo(row + 1);
        chName.setText(channelConfigInfo.getSensorName());
        setHgrow(chName, Priority.ALWAYS);

        ChannelButton chVal = new ChannelButton(rowNumber, ChannelButtonRole.CH_VALUE);
        chVal.setText("-");
        setHgrow(chVal, Priority.ALWAYS);

        buttons.add(chNum);
        buttons.add(chName);
        buttons.add(chVal);

        super.getChildren().addAll(chNum, chName, chVal);

        sceneProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                DoubleBinding multiply = Bindings.multiply(1. / 7., newValue.widthProperty());
                chNum.prefWidthProperty().bind(multiply);
                chName.prefWidthProperty().bind(multiply);
                chVal.prefWidthProperty().bind(multiply);
            }
            ;
        });

        update();
    }

    private void update() {
        final Runnable updater = () -> {
            // get information on background thread
            ChannelDataPeriodicModel channelDataPeriod = channelConfigService.getChannelDataPeriod(rowNumber);

            // update UI on FX thread
            Platform.runLater(
                    () -> {
                        if (channelDataPeriod != null) {
                            switch (channelDataPeriod.getCurrentError()) {
                                case NORMAL:
                                    setState(ChannelButtonState.CH_AVAILABLE);
                                    break;
                                case TIMEOUT:
                                case SOFTWARE:
                                    setState(ChannelButtonState.CH_NOT_AVAILABLE);
                                    break;
                                default:
                                    break;
                            }

                            buttons.get(2).setText(channelDataPeriod.getDataFisis());

                        } else {
                            setState(ChannelButtonState.CH_NOT_AVAILABLE);
                            buttons.get(2).setText("");
                        }
                    });
        };

        scheduledExecutorService.scheduleAtFixedRate(updater, 5000, 1000, TimeUnit.MILLISECONDS);
    }

    public void setState(ChannelButtonState state) {
        for (ChannelButton channelButton : buttons) {
            channelButton.setState(state);
        }
    }
}
