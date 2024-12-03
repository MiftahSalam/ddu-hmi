package skm.ddu.mlh.shared.configs;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ChannelAccessConfig {
    public static enum AccessType {
        DB,
        REST_API
    }

    private AccessType accessType;
    private String accessConfig;
}
