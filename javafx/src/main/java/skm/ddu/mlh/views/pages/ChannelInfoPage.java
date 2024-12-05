package skm.ddu.mlh.views.pages;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import lombok.extern.slf4j.Slf4j;
import skm.ddu.mlh.App;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.services.ChannelConfigService;

@Slf4j
public class ChannelInfoPage {
    private ChannelConfigService channelConfigService = ChannelConfigService.getInstance();

    @FXML
    private Button buttonOk;

    @FXML
    private Label labelChannelNumber;

    @FXML
    private Label labelAccessIP;

    @FXML
    private Label labelAccessPort;

    @FXML
    private Label labelCurrentError;

    @FXML
    private Label labelSensorName;

    @FXML
    private Label labelSerialBaudrate;

    @FXML
    private Label labelSerialDatabits;

    @FXML
    private Label labelSerialParity;

    @FXML
    private Label labelSerialStopbits;

    @FXML
    void onClicked(MouseEvent event) {
        try {
            App.selectHomePage();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public void setChannel(int chNum) {
        log.debug("channel: " + chNum);
        ChannelConfigInfoModel channelConfigInfo = channelConfigService.getChannelConfigInfo(chNum);

        labelChannelNumber.setText("Channel " + String.valueOf(chNum));
        labelAccessIP.setText(channelConfigInfo.getAccessIP());
        labelAccessPort.setText(channelConfigInfo.getAccessPort());
        labelCurrentError.setText(channelConfigInfo.getCurrentError());
        labelSensorName.setText(channelConfigInfo.getSensorName());
        labelSerialBaudrate.setText(channelConfigInfo.getSerialBaudrate());
        labelSerialDatabits.setText(channelConfigInfo.getSerialDatabits());
        labelSerialStopbits.setText(channelConfigInfo.getSerialStopbits());
        labelSerialParity.setText(channelConfigInfo.getSerialParity());
    }
}
