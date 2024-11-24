package skm.ddu.mlh.views.panels;

import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.components.ChannelRow;

public class ChannelsPanel extends VBox {
    public ChannelsPanel() {
        ChannelRow ch1 = new ChannelRow();
        ChannelRow ch2 = new ChannelRow();

        super.getChildren().addAll(ch1, ch2);
    }
}
