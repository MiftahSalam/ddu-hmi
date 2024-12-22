package skm.ddu.mlh.shared.exceptions;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@AllArgsConstructor
@Getter
@Setter
public class DDUBaseException extends RuntimeException {
    private Integer code;
    private String message;
}
