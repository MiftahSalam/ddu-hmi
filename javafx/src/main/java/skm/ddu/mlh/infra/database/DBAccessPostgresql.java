package skm.ddu.mlh.infra.database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.List;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresql implements DBAccess {
    private Connection connection = null;

    public DBAccessPostgresql(DatabaseConfig config) {
        try {
            String url = "jdbc:postgresql://" + config.getHost() + ":" + config.getPort() + "/" + config.getName()
                    + "?user=" + config.getUsername() + "&password=" + config.getPassword();
            // obtain a physical connection
            connection = DriverManager.getConnection(url, config.getUsername(), config.getPassword());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void executeUpdate(String sql) throws SQLException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'executeUpdate'");
    }

    @Override
    public int executeQuery(String query) throws SQLException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'executeQuery'");
    }

    @Override
    public List<List<String>> executeQueryAndReturnResult(String query) throws SQLException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'executeQueryAndReturnResult'");
    }
}
