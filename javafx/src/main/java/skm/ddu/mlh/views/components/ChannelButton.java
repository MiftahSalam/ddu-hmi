package skm.ddu.mlh.views.components;

import javafx.scene.control.Button;

public class ChannelButton extends Button {
    public enum ChannelButtonRole {
        CH_NUMBER,
        CH_NAME,
        CH_VALUE
    }

    private int chNum;
    private ChannelButtonRole chRole;

    public ChannelButton(int number, ChannelButtonRole role) {
        chNum = number;
        chRole = role;
    }
}
