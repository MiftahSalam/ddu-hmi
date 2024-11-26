package skm.ddu.mlh.views.panels;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.views.components.ChannelRow;

public class ChannelsPanel extends VBox {
    public ChannelsPanel() {
        HBox label = generateChannelLabelRow();
        HBox col1 = generateChannelRows1();
        HBox col2 = generateChannelRows2();

        setVgrow(label, Priority.ALWAYS);
        setVgrow(col1, Priority.ALWAYS);
        setVgrow(col2, Priority.ALWAYS);

        super.getChildren().add(label);
        super.getChildren().add(col1);
        super.getChildren().add(col2);
    }

    private HBox generateChannelRows1() {
        HBox box = new HBox();

        ChannelRow ch1 = new ChannelRow();
        ChannelRow ch2 = new ChannelRow();

        HBox.setHgrow(ch1, Priority.ALWAYS);
        HBox.setHgrow(ch2, Priority.ALWAYS);

        box.getChildren().add(ch1);
        box.getChildren().add(ch2);

        return box;
    }

    private HBox generateChannelRows2() {
        HBox box = new HBox();

        ChannelRow ch1 = new ChannelRow();
        ChannelRow ch2 = new ChannelRow();

        HBox.setHgrow(ch1, Priority.ALWAYS);
        HBox.setHgrow(ch2, Priority.ALWAYS);

        box.getChildren().add(ch1);
        box.getChildren().add(ch2);

        return box;
    }

    private HBox generateChannelLabelRow() {
        HBox box = new HBox();
        HBox box1 = generateLabelRow();
        HBox box2 = generateLabelRow();

        HBox.setHgrow(box1, Priority.ALWAYS);
        HBox.setHgrow(box2, Priority.ALWAYS);

        box.getChildren().addAll(box1, box2);

        return box;
    }

    private HBox generateLabelRow() {
        HBox box = new HBox();

        Label chNum = new Label();
        chNum.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        chNum.setText("CHANNEL");
        chNum.setAlignment(Pos.CENTER);
        HBox.setHgrow(chNum, Priority.ALWAYS);

        Label chName = new Label();
        chName.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        chName.setText("SENSOR");
        chName.setAlignment(Pos.CENTER);
        HBox.setHgrow(chName, Priority.ALWAYS);

        Label chVal = new Label();
        chVal.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        chVal.setText("VALUE");
        chVal.setAlignment(Pos.CENTER);
        HBox.setHgrow(chVal, Priority.ALWAYS);

        box.getChildren().addAll(chNum, chName, chVal);

        return box;
    }
}
