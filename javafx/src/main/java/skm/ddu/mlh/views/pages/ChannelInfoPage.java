package skm.ddu.mlh.views.pages;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import skm.ddu.mlh.App;

public class ChannelInfoPage {

    @FXML
    private Button buttonOk;

    @FXML
    void onClicked(MouseEvent event) {
        try {
            App.selectHomePage();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
