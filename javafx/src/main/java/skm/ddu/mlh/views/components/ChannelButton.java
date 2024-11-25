package skm.ddu.mlh.views.components;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import lombok.extern.slf4j.Slf4j;

@Slf4j
public class ChannelButton extends Button {
    public enum ChannelButtonRole {
        CH_NUMBER,
        CH_NAME,
        CH_VALUE
    }

    private int chNum;
    private ChannelButtonRole chRole;

    public ChannelButton(int number, ChannelButtonRole role) {
        setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

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
                    };
                };
                break;
            case CH_NAME:
                click = new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        // TODO: call info page
                        log.debug("button ch: " + chNum + ", role: " + role.name());
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
}
