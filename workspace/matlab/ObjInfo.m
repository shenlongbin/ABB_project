clear
close all
clc

obj_type_string = {'stick', 'screw', 'cube', 'disk'};
points_string = {'1', '2', '3', '4', '5', '6', '7', '8'};
file_path = '../../Data/ObjectInfo.txt';
fid = fopen(file_path);

tline = fgetl(fid);
ct = 0;
while ischar(tline)
    if strcmp(tline, 'name')
    objInfo.name            =  fgetl(fid);
    end
    if strcmp(tline, 'corner_points')
    objInfo.corner_points   = str2num( fgetl(fid) );
    end
    if strcmp(tline, 'Gsp_Direction')
    objInfo.gsp_direction   = str2num( fgetl(fid) );
    end
    if strcmp(tline, 'Gsp_Width')
    objInfo.gsp_width       = str2num( fgetl(fid) );
    end
    if strcmp(tline, 'Obj_Center')
    objInfo.obj_center      = str2num( fgetl(fid) );
    end
    if strcmp(tline, '-----')
        ct = ct+1;
% print object info
%         disp('object name');
%         disp(objInfo.name);
%         disp('corner points');
%         pp = objInfo.corner_points;
%         for i = 1: length(points_string)
%             disp([num2str(pp(i)), ' ', num2str(pp(i+8)), ' ', num2str(pp(i+16))]);
%         end
%         disp('grasp dir');
%         disp(objInfo.gsp_direction);
%         disp('grasp width');
%         disp(objInfo.gsp_width);
%         disp('center');
%         disp(objInfo.obj_center);
        %figure        
% corner points
if 13 == ct || 16 ==ct
plot3(objInfo.corner_points(1:8), ...
      objInfo.corner_points(9:16),...
      objInfo.corner_points(17:24), 'b.', 'MarkerSize', 14);
  
text(objInfo.corner_points(1:8), ...
      objInfo.corner_points(9:16),...
      objInfo.corner_points(17:24), points_string, 'Interpreter', 'Latex', 'FontSize', 20);
  
hold on
% center point
plot3(objInfo.obj_center(1), ...
      objInfo.obj_center(2), ...
      objInfo.obj_center(3), 'r.', 'MarkerSize', 14);
% grasp direction
arrow3(objInfo.corner_points(1:8:24), objInfo.corner_points(1:8:24) - objInfo.gsp_direction);
axis equal
title(objInfo.name);
xlabel('$x(mm)$', 'Interpreter', 'Latex', 'FontSize', 14);
ylabel('$y(mm)$', 'Interpreter', 'Latex', 'FontSize', 14);
end
    end
    tline = fgetl(fid);
end

fclose(fid);