package skm.ddu.mlh.views.panels;

import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.components.ChannelRow;

public class ChannelsPanel extends VBox {
    public ChannelsPanel() {
        ChannelRow ch1 = new ChannelRow();
        ChannelRow ch2 = new ChannelRow();
        ChannelRow ch3 = new ChannelRow();
        ChannelRow ch4 = new ChannelRow();

        setVgrow(ch1, Priority.ALWAYS);
        setVgrow(ch2, Priority.ALWAYS);
        setVgrow(ch3, Priority.ALWAYS);
        setVgrow(ch4, Priority.ALWAYS);

        super.getChildren().add(0, ch1);
        super.getChildren().add(1, ch2);
        super.getChildren().add(2, ch3);
        super.getChildren().add(3, ch4);
    }
}
