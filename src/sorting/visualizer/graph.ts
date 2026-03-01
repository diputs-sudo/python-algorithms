export class Graph {
    private container: HTMLElement;
    private bars: HTMLDivElement[] = [];

    constructor(containerId: string) {
        const element = document.getElementById(containerId);
        if (!element) {
            throw new Error("Graph container not found");
        }
        this.container = element;
    }

    public render(array: number[], highlight: number[] = [], type: string = "default") {
        this.container.innerHTML = "";
        this.bars = [];

        const max = Math.max(...array);

        array.forEach((value, index) => {
            const bar = document.createElement("div");
            bar.classList.add("bar");

            bar.style.height = `${(value / max) * 100}%`;

            if (highlight.includes(index)) {
                if (type === "compare") {
                    bar.style.backgroundColor = "#facc15";
                } else if (type === "swap") {
                    bar.style.backgroundColor = "#ef4444";
                }
            } else {
                bar.style.backgroundColor = "#3b82f6";
            }

            this.container.appendChild(bar);
            this.bars.push(bar);
        });
    }

    public markSorted() {
        this.bars.forEach(bar => {
            bar.style.backgroundColor = "#22c55e";
        });
    }
}