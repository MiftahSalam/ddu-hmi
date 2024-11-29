package skm.ddu.mlh.views.components;

import java.util.ArrayList;
import java.util.List;

import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonState;

public class ChannelRow extends HBox {
    private int rowNumber;
    private List<ChannelButton> buttons = new ArrayList<>();

    public ChannelRow(int row, String label) {
        rowNumber = row;

        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        ChannelButton chNum = new ChannelButton(rowNumber, ChannelButtonRole.CH_NUMBER);
        chNum.setText(label);
        setHgrow(chNum, Priority.ALWAYS);

        ChannelButton chName = new ChannelButton(rowNumber, ChannelButtonRole.CH_NAME);
        chName.setText("Speedlog 1");
        setHgrow(chName, Priority.ALWAYS);

        ChannelButton chVal = new ChannelButton(rowNumber, ChannelButtonRole.CH_VALUE);
        chVal.setText("2.3 kts");
        setHgrow(chVal, Priority.ALWAYS);

        buttons.add(chNum);
        buttons.add(chName);
        buttons.add(chVal);

        super.getChildren().addAll(chNum, chName, chVal);
    }

    public void setState(ChannelButtonState state) {
        for (ChannelButton channelButton : buttons) {
            channelButton.setState(state);
        }
    }
}
