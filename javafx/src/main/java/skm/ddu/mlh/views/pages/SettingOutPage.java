package skm.ddu.mlh.views.pages;

import java.io.IOException;
import java.net.URL;
import java.util.Map;
import java.util.ResourceBundle;
import java.util.stream.Collectors;

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
import skm.ddu.mlh.shared.constants.ChannelConstant;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_ASSIGN;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_IO_FUNCTION;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_JENIS_NMEA;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_NMEA_VALUE;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SENSOR_NAME;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_BAUDRATE;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_DATABITS;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_FLOW_CONTROL;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_PARITY;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_STOPBITS;

@Slf4j
public class SettingOutPage implements Initializable {

    @FXML
    private HBox hbox1;

    @FXML
    private Button buttonOK;

    @FXML
    private ComboBox<String> comboAssign;

    @FXML
    private ComboBox<String> comboAssignValue;

    @FXML
    private ComboBox<String> comboBaudrate;

    @FXML
    private ComboBox<String> comboDatabits;

    @FXML
    private ComboBox<String> comboFlow;

    @FXML
    private ComboBox<String> comboJenis;

    @FXML
    private ComboBox<String> comboNama;

    @FXML
    private ComboBox<String> comboParity;

    @FXML
    private ComboBox<String> comboStopbits;

    @FXML
    private ComboBox<String> comboValue;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        setupResponsive();

        setupComboJenis();
        setupComboName();
        setupSerialBaud();
        setupSerialDataBits();
        setupSerialStopBits();
        setupSerialParity();
        setupSerialFlow();
        setupOutputValue();
        setupAssignChannel();

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

    private void setupAssignChannelValue(CH_ASSIGN assign) {
        comboAssignValue.getItems().clear();

        switch (assign) {
            case CHANNEL:
                comboAssignValue.getItems().add("-");
                Map<Object, Object> map = ChannelConstant.CH_IO_MAP.entrySet().stream()
                        .filter(t -> t.getValue() == CH_IO_FUNCTION.IN)
                        .collect(Collectors.toMap(e -> e.getKey(), e -> e.getKey()));
                map.keySet().forEach(c -> {
                    comboAssignValue.getItems().add(Integer.toString((Integer) c));
                });
                comboAssignValue.setValue(comboValue.getItems().get(0));

                break;
            case JENIS:
                for (CH_JENIS_NMEA jenis : CH_JENIS_NMEA.values()) {
                    String name = jenis == CH_JENIS_NMEA.NONE ? "-" : jenis.name();

                    comboAssignValue.getItems().add(name);
                }
                comboAssignValue.setValue(comboAssignValue.getItems().get(0));

                break;
            default:
                break;
        }
    }

    private void setupAssignChannel() {
        for (CH_ASSIGN value : CH_ASSIGN.values()) {
            String name = value == CH_ASSIGN.NONE ? "-" : value.name();

            comboAssign.getItems().add(name);
        }
        comboAssign.setValue(comboValue.getItems().get(0));

        comboAssign.setOnAction(event -> {
            CH_ASSIGN assign;
            try {
                assign = CH_ASSIGN.valueOf(comboAssign.getValue());
            } catch (Exception e) {
                assign = CH_ASSIGN.NONE;
            }

            setupAssignChannelValue(assign);
        });
    }

    private void setupOutputValue() {
        for (CH_NMEA_VALUE value : CH_NMEA_VALUE.values()) {
            String name = value == CH_NMEA_VALUE.NONE ? "-" : value.name();

            comboValue.getItems().add(name);
        }
        comboValue.setValue(comboValue.getItems().get(0));
    }

    private void setupSerialFlow() {
        for (CH_SERIAL_FLOW_CONTROL flow : CH_SERIAL_FLOW_CONTROL.values()) {
            String name = flow == CH_SERIAL_FLOW_CONTROL.NONE ? "-" : flow.name();

            comboFlow.getItems().add(name);
        }
        comboFlow.setValue(comboFlow.getItems().get(0));
    }

    private void setupSerialParity() {
        for (CH_SERIAL_PARITY parity : CH_SERIAL_PARITY.values()) {
            String name = parity == CH_SERIAL_PARITY.NONE ? "-" : parity.name();

            comboParity.getItems().add(name);
        }
        comboParity.setValue(comboParity.getItems().get(0));
    }

    private void setupSerialStopBits() {
        for (CH_SERIAL_STOPBITS stopbits : CH_SERIAL_STOPBITS.values()) {
            String name = stopbits == CH_SERIAL_STOPBITS.NONE ? "-" : stopbits.name();

            comboStopbits.getItems().add(name.replaceAll("STOP_", ""));
        }
        comboStopbits.setValue(comboStopbits.getItems().get(0));
    }

    private void setupSerialDataBits() {
        for (CH_SERIAL_DATABITS databits : CH_SERIAL_DATABITS.values()) {
            String name = databits == CH_SERIAL_DATABITS.NONE ? "-" : databits.name();

            comboDatabits.getItems().add(name.replaceAll("DATA_", ""));
        }
        comboDatabits.setValue(comboDatabits.getItems().get(0));
    }

    private void setupSerialBaud() {
        for (CH_SERIAL_BAUDRATE baud : CH_SERIAL_BAUDRATE.values()) {
            String name = baud == CH_SERIAL_BAUDRATE.NONE ? "-" : baud.name();

            comboBaudrate.getItems().add(name.replaceAll("B_", ""));
        }
        comboBaudrate.setValue(comboBaudrate.getItems().get(0));
    }

    private void setupComboName() {
        for (CH_SENSOR_NAME sensor : CH_SENSOR_NAME.values()) {
            String name = sensor == CH_SENSOR_NAME.NONE ? "-" : sensor.name();

            comboNama.getItems().add(name.replaceAll("_", " "));
        }
        comboNama.setValue(comboNama.getItems().get(0));
    }

    private void setupComboJenis() {
        for (CH_JENIS_NMEA jenis : CH_JENIS_NMEA.values()) {
            String name = jenis == CH_JENIS_NMEA.NONE ? "-" : jenis.name();

            comboJenis.getItems().add(name);
        }
        comboJenis.setValue(comboJenis.getItems().get(0));
    }

    private void setupResponsive() {
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
    }
}