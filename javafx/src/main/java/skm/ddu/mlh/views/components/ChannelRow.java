package skm.ddu.mlh.views.components;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.RandomStringUtils;

import javafx.beans.binding.Bindings;
import javafx.beans.binding.DoubleBinding;
import javafx.geometry.Insets;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.services.ChannelConfigService;
import skm.ddu.mlh.shared.constants.ChannelConstant;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonState;

public class ChannelRow extends HBox {
    private final int rowNumber;
    private final ChannelConstant.CH_IO_FUNCTION ioFunction;
    private final List<ChannelButton> buttons = new ArrayList<>();
    private ChannelConfigService channelConfigService = ChannelConfigService.getInstance();

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
        chVal.setText(RandomStringUtils.randomAlphabetic(15));
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
    }

    public void setState(ChannelButtonState state) {
        for (ChannelButton channelButton : buttons) {
            channelButton.setState(state);
        }
    }
}
