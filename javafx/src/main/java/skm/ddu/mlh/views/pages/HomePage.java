package skm.ddu.mlh.views.layouts;

import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.panels.ChannelsPanel;

public class HomePage extends HBox {
    private ChannelsPanel chPannel;
    private ChannelsPanel chPannel1;
    Button pageButton;
    private int currenPage = 0;

    public HomePage() {
        try {
            chPannel = new ChannelsPanel(0, 7);
            chPannel1 = new ChannelsPanel(13, 19);

            VBox rightBar = createRightBar();

            rightBar.prefHeightProperty().bind(chPannel.heightProperty().multiply(0.2));
            rightBar.prefWidthProperty().bind(chPannel.widthProperty().multiply(0.2));

            setHgrow(chPannel, Priority.ALWAYS);
            setHgrow(chPannel1, Priority.ALWAYS);
            setHgrow(rightBar, Priority.SOMETIMES);

            super.getChildren().add(0, chPannel);
            ;
            super.getChildren().add(1, rightBar);
            ;
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private VBox createRightBar() {
        VBox boxBar = new VBox();
        VBox boxButton = new VBox();

        boxButton.prefHeightProperty().bind(boxBar.heightProperty().multiply(0.3));

        Region spacer = new Region();
        pageButton = new Button("NEXT");
        Button exitButton = new Button("SHUTDOWN");

        exitButton.getStyleClass().add("notAvail");

        String curStylePage = pageButton.getStyle() + "-fx-background-color: green; -fx-font-size: 14pt;";
        String curStyleExit = exitButton.getStyle() + "-fx-font-size: 14pt;";

        pageButton.setStyle(curStylePage);
        exitButton.setStyle(curStyleExit);
        pageButton.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        exitButton.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

        pageButton.setOnMouseClicked(event -> {
            onPageClicked();
        });

        VBox.setVgrow(spacer, Priority.ALWAYS);
        VBox.setVgrow(pageButton, Priority.ALWAYS);
        VBox.setVgrow(exitButton, Priority.ALWAYS);

        boxButton.getChildren().addAll(pageButton, exitButton);

        boxBar.getChildren().addAll(spacer, boxButton);

        return boxBar;
    }

    private void onPageClicked() {
        System.out.println("onPageClicked");
        ChannelsPanel channelsPanel;
        if (currenPage == 0) {
            channelsPanel = chPannel1;
            currenPage = 1;
            pageButton.setText("BACK");
        } else {
            channelsPanel = chPannel;
            currenPage = 0;
            pageButton.setText("NEXT");
        }

        super.getChildren().remove(0);
        super.getChildren().add(0, channelsPanel);
    }
}
