package skm.ddu.mlh.views.panels;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import skm.ddu.mlh.shared.constants.GlobalConstant;
import skm.ddu.mlh.views.components.ChannelRow;

public class ChannelsPanel extends VBox {
    private final int CHANNELS_PER_PAGE = GlobalConstant.CHANNEL_COUNT / GlobalConstant.CHANNEL_PAGE;
    private final int CHANNELS_PER_COLUMN = CHANNELS_PER_PAGE / 2;

    public ChannelsPanel() {
        HBox label = generateChannelLabelRow();
        setVgrow(label, Priority.ALWAYS);
        super.getChildren().add(label);

        for (int i = 0; i < CHANNELS_PER_COLUMN; i++) {
            HBox row = generateChannelRows(i);
            setVgrow(row, Priority.ALWAYS);
            super.getChildren().add(row);
        }
    }

    private HBox generateChannelRows(int index) {
        HBox box = new HBox();

        ChannelRow col1 = new ChannelRow(index, String.format("%d\n(IN)", index + 1));
        ChannelRow col2 = new ChannelRow(index + CHANNELS_PER_COLUMN,
                String.format("%d\n(IN)", index + CHANNELS_PER_COLUMN + 1));

        HBox.setHgrow(col1, Priority.ALWAYS);
        HBox.setHgrow(col2, Priority.ALWAYS);

        box.getChildren().add(col1);
        box.getChildren().add(col2);

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

        Label chNum = createLabel("CHANNEL");
        Label chName = createLabel("SENSOR");
        Label chVal = createLabel("VALUE");

        box.getChildren().addAll(chNum, chName, chVal);

        return box;
    }

    private Label createLabel(String text) {
        Label label = new Label();
        label.getStyleClass().add("label-channel");
        label.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        label.setText(text);
        label.setAlignment(Pos.CENTER);

        HBox.setHgrow(label, Priority.ALWAYS);

        return label;
    }
}
