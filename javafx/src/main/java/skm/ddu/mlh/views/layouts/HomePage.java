package skm.ddu.mlh.views.layouts;

import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.panels.ChannelsPanel;

public class HomePage extends VBox {

    public HomePage() {
        ChannelsPanel ch = new ChannelsPanel();

        setVgrow(ch, Priority.ALWAYS);

        super.getChildren().add(ch);
    }
}
