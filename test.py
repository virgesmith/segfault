import pytest
import example


def test_segfault() -> None:
    with pytest.raises(ValueError):
        example.sqrt(-4)


if __name__ == "__main__":
    try:
        example.sqrt(-4)
    except Exception as e:
        print(e)
