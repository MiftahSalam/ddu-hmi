package skm.ddu.mlh.views.pages;

import java.io.IOException;
import java.net.URL;
import java.util.List;
import java.util.Map;
import java.util.ResourceBundle;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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
import skm.ddu.mlh.views.utils.ViewUtils;

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
                List<String> list = Stream.of(CH_JENIS_NMEA.values()).map(Enum::name).collect(Collectors.toList());
                ViewUtils.initCombobox(comboAssignValue, list, 0, "", "");

                break;
            default:
                break;
        }
    }

    private void setupAssignChannel() {
        List<String> list = Stream.of(CH_ASSIGN.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboAssign, list, 0, "", "");

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
        List<String> list = Stream.of(CH_NMEA_VALUE.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboValue, list, 0, "", "");
    }

    private void setupSerialFlow() {
        List<String> list = Stream.of(CH_SERIAL_FLOW_CONTROL.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboFlow, list, 0, "", "");
    }

    private void setupSerialParity() {
        List<String> list = Stream.of(CH_SERIAL_PARITY.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboParity, list, 0, "", "");
    }

    private void setupSerialStopBits() {
        List<String> list = Stream.of(CH_SERIAL_STOPBITS.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboStopbits, list, 0, "STOP_", "");
    }

    private void setupSerialDataBits() {
        List<String> list = Stream.of(CH_SERIAL_DATABITS.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboDatabits, list, 0, "DATA_", "");
    }

    private void setupSerialBaud() {
        List<String> list = Stream.of(CH_SERIAL_BAUDRATE.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboBaudrate, list, 0, "B_", "");
    }

    private void setupComboName() {
        List<String> list = Stream.of(CH_SENSOR_NAME.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboNama, list, 0, "_", " ");
    }

    private void setupComboJenis() {
        List<String> list = Stream.of(CH_JENIS_NMEA.values()).map(Enum::name).collect(Collectors.toList());
        ViewUtils.initCombobox(comboJenis, list, 0, "", "");
        // for (CH_JENIS_NMEA jenis : CH_JENIS_NMEA.values()) {
        // String name = jenis == CH_JENIS_NMEA.NONE ? "-" : jenis.name();

        // comboJenis.getItems().add(name);
        // }
        // comboJenis.setValue(comboJenis.getItems().get(0));
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