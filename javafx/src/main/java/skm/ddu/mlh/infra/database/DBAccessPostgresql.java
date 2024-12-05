package skm.ddu.mlh.infra.database;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresql implements DBAccess {
    private HikariDataSource dataSource;
    private static DBAccessPostgresql instance;

    private DBAccessPostgresql(DatabaseConfig config) {
        HikariConfig hikariConfig = new HikariConfig();
        String url = "jdbc:postgresql://" + config.getHost() + ":" + config.getPort() + "/" + config.getName();

        hikariConfig.setJdbcUrl(url);
        hikariConfig.setPassword(config.getPassword());
        hikariConfig.setUsername(config.getUsername());
        hikariConfig.setMaximumPoolSize(10);
        hikariConfig.setMinimumIdle(5);
        hikariConfig.setIdleTimeout(60_000);
        hikariConfig.setMaxLifetime(60 * 60 * 1000);

        dataSource = new HikariDataSource(hikariConfig);
    }

    public static DBAccessPostgresql getInstance(DatabaseConfig config) {
        if (instance == null) {
            instance = new DBAccessPostgresql(config);
        }

        return instance;
    }

    @Override
    public int executeUpdate(String sql) throws SQLException {
        int result = -1;
        try (Connection connection = dataSource.getConnection();
                PreparedStatement statement = connection.prepareStatement(
                        sql,
                        ResultSet.TYPE_SCROLL_INSENSITIVE,
                        ResultSet.CONCUR_READ_ONLY);) {
            result = statement.executeUpdate();
        } catch (Exception e) {
            throw e;
        }

        return result;
    }

    @Override
    public int executeQuery(String query) throws SQLException {
        int result = -1;
        try (Connection connection = dataSource.getConnection();
                PreparedStatement statement = connection.prepareStatement(
                        query,
                        ResultSet.TYPE_SCROLL_INSENSITIVE,
                        ResultSet.CONCUR_READ_ONLY);) {
            ResultSet resultSet = statement.executeQuery();
            resultSet.last();
            result = resultSet.getRow();
        } catch (Exception e) {
            throw e;
        }

        return result;
    }

    @Override
    public List<List<String>> executeQueryAndReturnResult(String query) throws SQLException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'executeQueryAndReturnResult'");
    }

    @Override
    public void close() {
        if (instance != null) {
            instance.dataSource.close();
        }
    }
}
