from launch import LaunchDescription
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescrption([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '~/pupsense_ws/launch/room.sdf'],
            output='screen'),
        ])
