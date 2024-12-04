package skm.ddu.mlh.shared.configs;

import java.io.File;

import org.apache.commons.configuration2.Configuration;
import org.apache.commons.configuration2.builder.fluent.Configurations;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class ChannelAccessConfig {
    public static enum AccessType {
        DB,
        REST_API
    }

    private AccessType accessType;
    private String accessConfig;
    private static ChannelAccessConfig instance;

    private ChannelAccessConfig(AccessType accessType, String accessConfig) {
        this.accessType = accessType;
        this.accessConfig = accessConfig;

        log.debug("access type: " + accessType);
        log.debug("access config: " + accessConfig);
    }

    public AccessType getAccessType() {
        return accessType;
    }

    public String getAccessConfig() {
        return accessConfig;
    }

    public static ChannelAccessConfig getInstance() {
        if (instance == null) {
            Configurations configs = new Configurations();
            try {
                Configuration config = configs.properties(new File("application.properties"));

                instance = new ChannelAccessConfig(
                        AccessType.valueOf(config.getString("channel.access.type")),
                        config.getString("channel.access.config"));

            } catch (Exception e) {
                // TODO: handle exception
                log.error("error read app config");
            }
        }

        return instance;
    }
}
