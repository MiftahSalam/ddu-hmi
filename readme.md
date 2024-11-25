# run dev

- `mvn javafx:run`

# build

- jlink:

  - external package must have module-info.java
  - module-info.java must exist

    - template

      ```
        module skm.ddu.mlh {
            requires javafx.controls;
            requires javafx.fxml;

            opens skm.ddu.mlh to javafx.fxml;
            exports skm.ddu.mlh;
        }
      ```

  - execute: `mvn clean javafx:jlink`

- exe jar: `mvn clean install`

# run build

- jlink image
  - execute: `image/bin/java --module skm.ddu.mlh/skm.ddu.mlh.App`
- exe jar
  - execute: `java -jar -Dlog4j.configurationFile="./log4j2.xml" --module-path $JAVAFX_PATH --add-modules javafx.base,javafx.controls,javafx.fxml,javafx.graphics,javafx.media ./javafx-1.0-jar-with-dependencies.jar`
