package skm.ddu.mlh.views.components;

import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.text.TextAlignment;
import lombok.extern.slf4j.Slf4j;
import skm.ddu.mlh.App;

@Slf4j
public class ChannelButton extends Button {
    public enum ChannelButtonRole {
        CH_NUMBER,
        CH_NAME,
        CH_VALUE
    }

    public enum ChannelButtonState {
        CH_AVAILABLE,
        CH_NOT_AVAILABLE,
        CH_DISABLE
    }

    private int chNum;
    private ChannelButtonRole chRole;

    public ChannelButton(int number, ChannelButtonRole role) {
        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        setTextAlignment(TextAlignment.CENTER);

        setState(ChannelButtonState.CH_NOT_AVAILABLE);

        chNum = number;
        chRole = role;

        EventHandler<ActionEvent> click;
        switch (chRole) {
            case CH_NUMBER:
                click = new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        // TODO: call setting page

                        log.debug("button ch: " + chNum + ", role: " + role.name());

                        try {
                            App.selectChannelInfoPage(chNum);
                        } catch (IOException e) {
                            // TODO Auto-generated catch block
                            e.printStackTrace();
                        }
                    };
                };
                break;
            case CH_NAME:
                click = new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        // TODO: call info page
                        log.debug("button ch: " + chNum + ", role: " + role.name());

                        try {
                            App.selectSettingOutPage(chNum);
                        } catch (IOException e) {
                            // TODO Auto-generated catch block
                            e.printStackTrace();
                        }
                    };
                };
                break;
            default:
                click = new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        log.debug("button ch: " + chNum + ", role: " + role.name());
                    };
                };
                break;
        }

        setOnAction(click);
    }

    public void setState(ChannelButtonState state) {
        switch (state) {
            case CH_AVAILABLE:
                getStyleClass().remove("notAvail");
                getStyleClass().add("avail");
                break;
            default:
                getStyleClass().remove("avail");
                getStyleClass().add("notAvail");
                break;
        }
    }
}
