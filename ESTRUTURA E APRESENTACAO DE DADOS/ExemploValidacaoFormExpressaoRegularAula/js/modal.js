export class Modal {
    constructor(modalId, btnId) {
        this.modal = document.getElementById(modalId);
        this.openBtn = document.getElementById(btnId);
        this.closeBtn = this.modal.querySelector(".close");

        this.initEvents();
    }

    initEvents() {
        if (this.openBtn) {
            this.openBtn.addEventListener("click", () => this.open());
        }

        if (this.closeBtn) {
            this.closeBtn.addEventListener("click", () => this.close());
        }

        window.addEventListener("click", (event) => {
            if (event.target === this.modal) {
                this.close();
            }
        });
    }

    open() {
        this.modal.style.display = "block";
    }

    close() {
        this.modal.style.display = "none";
    }
}
