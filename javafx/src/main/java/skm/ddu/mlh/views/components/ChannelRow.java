package skm.ddu.mlh.views.components;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.RandomStringUtils;

import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import skm.ddu.mlh.shared.constants.ChannelConstant;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonState;

public class ChannelRow extends HBox {
    private final int rowNumber;
    private final ChannelConstant.CH_IO_FUNCTION ioFunction;
    private final List<ChannelButton> buttons = new ArrayList<>();

    public ChannelRow(int row) {
        rowNumber = row;
        ioFunction = ChannelConstant.CH_IO_MAP.get(row);

        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        ChannelButton chNum = new ChannelButton(rowNumber, ChannelButtonRole.CH_NUMBER);
        chNum.setText(String.format("%d\n(%s)", row + 1, ioFunction.toString()));
        setHgrow(chNum, Priority.ALWAYS);

        ChannelButton chName = new ChannelButton(rowNumber, ChannelButtonRole.CH_NAME);
        chName.setText(RandomStringUtils.randomAlphabetic(15));
        setHgrow(chName, Priority.ALWAYS);

        ChannelButton chVal = new ChannelButton(rowNumber, ChannelButtonRole.CH_VALUE);
        chVal.setText(RandomStringUtils.randomAlphabetic(15));
        setHgrow(chVal, Priority.ALWAYS);

        buttons.add(chNum);
        buttons.add(chName);
        buttons.add(chVal);

        super.getChildren().addAll(chNum, chName, chVal);

        chNum.prefWidthProperty().bind(widthProperty().divide(3));
        chName.prefWidthProperty().bind(widthProperty().divide(3));
        chVal.prefWidthProperty().bind(widthProperty().divide(3));
    }

    public void setState(ChannelButtonState state) {
        for (ChannelButton channelButton : buttons) {
            channelButton.setState(state);
        }
    }
}
