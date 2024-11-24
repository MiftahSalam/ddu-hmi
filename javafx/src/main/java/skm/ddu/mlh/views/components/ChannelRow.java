package skm.ddu.mlh.views.components;

import javafx.scene.layout.HBox;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;

public class ChannelRow extends HBox {
    public ChannelRow() {
        ChannelButton chNum = new ChannelButton(1, ChannelButtonRole.CH_NUMBER);
        chNum.setText("Channel 1");

        ChannelButton chName = new ChannelButton(1, ChannelButtonRole.CH_NAME);
        chName.setText("Speedlog 1");

        ChannelButton chVal = new ChannelButton(1, ChannelButtonRole.CH_VALUE);
        chVal.setText("2.3 kts");

        super.getChildren().addAll(chNum, chName, chVal);
    }
}
