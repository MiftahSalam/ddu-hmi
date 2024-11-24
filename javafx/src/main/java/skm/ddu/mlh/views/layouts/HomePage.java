package skm.ddu.mlh.views.layouts;

import javafx.scene.Parent;
import skm.ddu.mlh.views.panels.ChannelsPanel;

public class HomePage extends Parent {

    public HomePage() {
        ChannelsPanel ch = new ChannelsPanel();

        super.getChildren().add(ch);
    }
}
