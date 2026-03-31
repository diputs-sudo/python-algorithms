import { Graph } from "./sorting/visualizer/graph.js";
import { bubbleSort } from "./sorting/algorithms/bubble.js";

document.addEventListener("DOMContentLoaded", () => {
    const container = document.getElementById("homeGraphContainer");

    if (!container) return;

    const graph = new Graph("homeGraphContainer");
    const dataset = [62, 18, 44, 12, 86, 30, 71, 24];
    const stepDelay = 180;
    const restartDelay = 3000;

    let timerId: number | null = null;
    let restartId: number | null = null;
    let generator = bubbleSort(dataset);

    function clearTimers() {
        if (timerId !== null) {
            window.clearInterval(timerId);
            timerId = null;
        }

        if (restartId !== null) {
            window.clearTimeout(restartId);
            restartId = null;
        }
    }

    function runLoop() {
        clearTimers();
        generator = bubbleSort(dataset);
        graph.render(dataset);

        timerId = window.setInterval(() => {
            const result = generator.next();

            if (result.done || result.value.type === "done") {
                clearTimers();
                graph.markSorted();
                restartId = window.setTimeout(runLoop, restartDelay);
                return;
            }

            graph.render(
                result.value.array,
                result.value.indices,
                result.value.type
            );
        }, stepDelay);
    }

    runLoop();
});
