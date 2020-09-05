#include <cstdio>

class MinStack {
public:
	int stack[10005], mins[10005], top=0, minn=0x7fffffff;
	memest(stack, 0, sizeof(stack));
	memest(mins, 0, sizeof(mins));
    MinStack() {
    }
    void push(int x) {
    	stack[top]=x;
	minn=minn>x?x:minn;
	mins[top]=minn;
	top++;
    }
    void pop() {
    	top--;
	minn=mins[top];
    }
    int top() {
    	return stack[top-1];
    }
    int getMin() {
    	return minn;
    }
};

int main(){
	MinStack minStack = new MinStack();
	minStack.push(-1);
	minStack.push(3);
	minStack.push(-4);
	printf("%d", minStack.getMin());

	return 0;
}
