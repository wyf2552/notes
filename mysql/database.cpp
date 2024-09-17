编队类型
CREATE TABLE formation (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL
);

无人机配置表 (drone_configuration)
CREATE TABLE drone_configuration (
    id INT PRIMARY KEY AUTO_INCREMENT,
    formation_id INT NOT NULL,
    drone_count INT NOT NULL,
    x int NOT NULL,
    y int NOT NULL,
    z int NOT NULL,
    FOREIGN KEY (formation_id) REFERENCES formation(id)
);

适用场景表
CREATE TABLE scenario (
    id INT PRIMARY KEY AUTO_INCREMENT,
    formation_id INT NOT NULL,
    description TEXT NOT NULL,
    FOREIGN KEY (formation_id) REFERENCES formation(id)
);

载荷表
CREATE TABLE payload (
    id INT PRIMARY KEY AUTO_INCREMENT,
    formation_id INT NOT NULL,
    name VARCHAR(100) NOT NULL,
    FOREIGN KEY (formation_id) REFERENCES formation(id)
);

相对位置表 (relative_position)
CREATE TABLE relative_position (
    id INT PRIMARY KEY AUTO_INCREMENT,
    drone_config_id INT NOT NULL,
    position_matrix TEXT,
    FOREIGN KEY (drone_config_id) REFERENCES drone_configuration(id)
);

相对矩阵 (relative_matrix)
CREATE TABLE relative_position (
    id INT PRIMARY KEY AUTO_INCREMENT,
    drone_config_id INT NOY NULL,
    x int NOT NULL,
    y int NOT NULL,
    z int NOT NULL,
    FOREIGN KEY (drone_config_id) REFERENCES drone_configuration(id)
);







