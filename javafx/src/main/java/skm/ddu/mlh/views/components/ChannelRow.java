package skm.ddu.mlh.views.components;

import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import skm.ddu.mlh.views.components.ChannelButton.ChannelButtonRole;

public class ChannelRow extends HBox {
    private int rowNumber;

    public ChannelRow(int row, String label) {
        rowNumber = row;

        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        ChannelButton chNum = new ChannelButton(1, ChannelButtonRole.CH_NUMBER);
        chNum.setText(label);
        setHgrow(chNum, Priority.ALWAYS);

        ChannelButton chName = new ChannelButton(1, ChannelButtonRole.CH_NAME);
        chName.setText("Speedlog 1");
        setHgrow(chName, Priority.ALWAYS);

        ChannelButton chVal = new ChannelButton(1, ChannelButtonRole.CH_VALUE);
        chVal.setText("2.3 kts");
        setHgrow(chVal, Priority.ALWAYS);

        super.getChildren().addAll(chNum, chName, chVal);
    }
}
