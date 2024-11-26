package skm.ddu.mlh.views.layouts;

import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.panels.ChannelsPanel;

public class HomePage extends HBox {

    public HomePage() {
        ChannelsPanel ch = new ChannelsPanel();
        VBox rightBar = createRightBar();

        rightBar.prefHeightProperty().bind(ch.heightProperty().multiply(0.2));
        rightBar.prefWidthProperty().bind(ch.widthProperty().multiply(0.2));

        setHgrow(ch, Priority.ALWAYS);
        setHgrow(rightBar, Priority.SOMETIMES);

        super.getChildren().addAll(ch, rightBar);
    }

    private VBox createRightBar() {
        VBox boxBar = new VBox();
        VBox boxButton = new VBox();

        boxButton.prefHeightProperty().bind(boxBar.heightProperty().multiply(0.3));

        Region spacer = new Region();
        Button pageButton = new Button("NEXT");
        Button exitButton = new Button("SHUTDOWN");

        exitButton.getStyleClass().add("notAvail");

        String curStylePage = pageButton.getStyle() + "-fx-background-color: green; -fx-font-size: 14pt;";
        String curStyleExit = exitButton.getStyle() + "-fx-font-size: 14pt;";

        pageButton.setStyle(curStylePage);
        exitButton.setStyle(curStyleExit);
        pageButton.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        exitButton.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        VBox.setVgrow(spacer, Priority.ALWAYS);
        VBox.setVgrow(pageButton, Priority.ALWAYS);
        VBox.setVgrow(exitButton, Priority.ALWAYS);

        boxButton.getChildren().addAll(pageButton, exitButton);

        boxBar.getChildren().addAll(spacer, boxButton);

        return boxBar;
    }
}
