#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "BRKDEC.h"

static int mix_value(int x, int seed) {
    BRKDEC_FUNC_BOUNDARY;
    int v = x ^ (seed * 31);

    if ((v & 1) == 0) {
        v += 7;
    } else {
        v -= 3;
    }

    if (v < 0) {
        v = -v;
    }

    return v;
}

static int transform_item(int value, int index, int mode) {
    BRKDEC_FUNC_BOUNDARY;
    int out = value;

    switch (mode % 4) {
        case 0:
            out += index;
            break;
        case 1:
            out -= index * 2;
            break;
        case 2:
            out ^= (index + 11);
            break;
        default:
            out = (out * 3) - index;
            break;
    }

    if (out > 100) {
        out /= 2;
    } else if (out < -50) {
        out += 25;
    } else {
        out += 1;
    }

    return out;
}

int analyze_buffer(const int *buf, int len, int seed) {
    BRKDEC_FUNC_BOUNDARY;
    int score = 0;
    int penalty = 0;
    int i;

    for (i = 0; i < len; i++) {
        int cur = buf[i];
        int mixed = mix_value(cur, seed);

        if (cur == 0) {
            penalty += 3;
            continue;
        }

        if ((mixed % 5) == 0) {
            score += transform_item(mixed, i, 0);
        } else if ((mixed % 3) == 0) {
            score += transform_item(mixed, i, 1);
        } else {
            score += transform_item(mixed, i, 2);
        }

        if ((score & 1) == 0) {
            penalty += i;
        } else {
            penalty += (cur & 3);
        }

        if (score > 500) {
            break;
        }
    }

    if (i == len) {
        score -= penalty;
    } else {
        score += penalty;
    }

    return score;
}

int classify_score(int score) {
    BRKDEC_FUNC_BOUNDARY;
    if (score < 0) {
        return -1;
    } else if (score < 100) {
        return 0;
    } else if (score < 300) {
        return 1;
    } else {
        return 2;
    }
}

int main(void) {
    BRKDEC_FUNC_BOUNDARY;
    int data[] = {12, 7, 0, 31, 44, 9, 18, 5, 27, 63};
    int len = (int)(sizeof(data) / sizeof(data[0]));
    int seed = 13;

    int score = analyze_buffer(data, len, seed);
    int cls = classify_score(score);
    
    printf("score = %d\n", score);
    printf("class = %d\n", cls);

    return 0;
}