package com.neborosoft.androidutils

import kotlin.math.absoluteValue

fun <T> List<T>.withPrependedItem(item: T): List<T> {
    return object : AbstractList<T>() {
        override val size: Int
            get() = this@withPrependedItem.size + 1

        override fun get(index: Int): T {
            if (index == 0) {
                return item
            } else {
                return this@withPrependedItem[index - 1]
            }
        }

    }
}

fun <T> List<T>.withAppendedItem(item: T): List<T> {
    return object : AbstractList<T>() {
        override val size: Int
            get() = this@withAppendedItem.size + 1

        override fun get(index: Int): T {
            if (index == size - 1) {
                return item
            } else {
                return this@withAppendedItem[index]
            }
        }

    }
}

fun <T> List<T>.shifted(by: Int): List<T> {
    return object : AbstractList<T>() {
        override val size: Int
            get() = this@shifted.size - by.absoluteValue

        override fun get(index: Int): T {
            return this@shifted[index + by]
        }
    }
}

fun <T> List<T>.removeFirstIfEquals(item: T): List<T> {
    return if (isEmpty()) {
        this
    } else if(first() == item) {
        shifted(1)
    } else {
        this
    }
}

fun <T> List<T>.getOrNull(index: Int): T? {
    return if (index < 0 || index >= size) {
        null
    } else {
        get(index)
    }
}

fun <T1, T2> List<T1>.contentEqualsUsingPredicate(other: List<T2>, predicate: (T1, T2) -> Boolean): Boolean {
    if (other.size != size) {
        return false
    }

    this.zip(other).forEach {
        if (!predicate(it.first, it.second)) {
            return false
        }
    }

    return true
}