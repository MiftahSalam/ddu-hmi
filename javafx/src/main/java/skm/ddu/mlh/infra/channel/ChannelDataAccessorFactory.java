package skm.ddu.mlh.infra.channel;

import skm.ddu.mlh.shared.configs.ChannelAccessConfig;

public class ChannelDataAccessorFactory {
    private static ChannelDataAccessor channelDataAccessor;

    public static ChannelDataAccessor build() {
        ChannelAccessConfig instance = ChannelAccessConfig.getInstance();
        switch (instance.getAccessType()) {
            case DB:
                channelDataAccessor = new ChannelDataAccessorDB(instance.getAccessConfig());
                break;
            default:
                break;
        }

        return channelDataAccessor;
    }

    public static void destroy() {
        if (channelDataAccessor != null) {
            channelDataAccessor.close();
        }
    }
}
