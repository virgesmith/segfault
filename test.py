import pytest
import example


def test_segfault() -> None:
    with pytest.raises(ValueError):
        example.sqrt(-4)
    # except Exception as e:
    #     print(e)
    # assert False

