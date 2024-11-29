package skm.ddu.mlh.views.pages;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.beans.binding.Bindings;
import javafx.beans.binding.DoubleBinding;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.HBox;
import lombok.extern.slf4j.Slf4j;
import skm.ddu.mlh.App;

@Slf4j
public class SettingOutPage implements Initializable {

    @FXML
    private HBox hbox1;

    @FXML
    private Button buttonOK;

    @FXML
    private ComboBox<?> comboAssign;

    @FXML
    private ComboBox<?> comboAssignValue;

    @FXML
    private ComboBox<?> comboBaudrate;

    @FXML
    private ComboBox<?> comboDatabits;

    @FXML
    private ComboBox<?> comboFlow;

    @FXML
    private ComboBox<String> comboJenis;

    @FXML
    private ComboBox<?> comboNama;

    @FXML
    private ComboBox<?> comboParity;

    @FXML
    private ComboBox<?> comboStopbits;

    @FXML
    private ComboBox<?> comboValue;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        hbox1.sceneProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                DoubleBinding multiply = Bindings.multiply(0.3, newValue.heightProperty());
                multiply.addListener(val -> {
                    hbox1.setPadding(new Insets(0, 0, multiply.doubleValue(), 0));
                    buttonOK.prefHeightProperty().bind(hbox1.heightProperty().multiply(0.05));
                });
                hbox1.setPadding(new Insets(0, 0, newValue.getHeight() * 0.3, 0));
                buttonOK.setPrefHeight(hbox1.getHeight() * 0.05);
            }
        });

        comboJenis.getItems().addAll("GP", "HE");
        comboJenis.setValue(comboJenis.getItems().get(0));

        buttonOK.setOnAction(event -> {
            try {
                App.selectHomePage();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        });
    }

    public void setChannel(int chNum) {
        log.debug("channel: " + chNum);
    }
}