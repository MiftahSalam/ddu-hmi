package skm.ddu.mlh.views.utils;

import java.util.List;

import javafx.scene.control.ComboBox;

public class ViewUtils {
    public static void initCombobox(ComboBox<String> combo, List<String> items, int selectedIdx,
            String replaceOldString, String replaceNewString) {
        for (String value : items) {
            String name = value == "NONE" ? "-" : value;

            combo.getItems().add(name.replaceAll(replaceOldString, replaceNewString));
        }
        combo.setValue(combo.getItems().get(selectedIdx));
    }
}
