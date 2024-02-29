# generated from rosidl_generator_py/resource/_idl.py.em
# with input from obj_msg:msg/Motion.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Motion(type):
    """Metaclass of message 'Motion'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('obj_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'obj_msg.msg.Motion')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motion
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motion
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motion
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motion
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motion

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Motion(metaclass=Metaclass_Motion):
    """Message class 'Motion'."""

    __slots__ = [
        '_x_cmd',
        '_y_cmd',
        '_yaw',
        '_depth',
    ]

    _fields_and_field_types = {
        'x_cmd': 'int32',
        'y_cmd': 'int32',
        'yaw': 'int32',
        'depth': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_cmd = kwargs.get('x_cmd', int())
        self.y_cmd = kwargs.get('y_cmd', int())
        self.yaw = kwargs.get('yaw', int())
        self.depth = kwargs.get('depth', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x_cmd != other.x_cmd:
            return False
        if self.y_cmd != other.y_cmd:
            return False
        if self.yaw != other.yaw:
            return False
        if self.depth != other.depth:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_cmd(self):
        """Message field 'x_cmd'."""
        return self._x_cmd

    @x_cmd.setter
    def x_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x_cmd' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x_cmd' field must be an integer in [-2147483648, 2147483647]"
        self._x_cmd = value

    @builtins.property
    def y_cmd(self):
        """Message field 'y_cmd'."""
        return self._y_cmd

    @y_cmd.setter
    def y_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y_cmd' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y_cmd' field must be an integer in [-2147483648, 2147483647]"
        self._y_cmd = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'yaw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'yaw' field must be an integer in [-2147483648, 2147483647]"
        self._yaw = value

    @builtins.property
    def depth(self):
        """Message field 'depth'."""
        return self._depth

    @depth.setter
    def depth(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'depth' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'depth' field must be an integer in [-2147483648, 2147483647]"
        self._depth = value
